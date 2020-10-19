#include "MyMainWindow.h"
#include<QApplication>
#include<QMenu>     //菜单类
#include<QMenuBar>  //菜单栏, MainWindow里边独有的
#include<QAction>   //每一个菜单项，快捷键也可以用
#include<QFileDialog>
#include<QFileInfo>
#include<qDebug>
#include<QToolBar>   //增加工具栏按钮
#include<QStatusBar>    //状态栏
#include<QLabel>
#include<QMouseEvent>
#include<QCursor>       //调整鼠标的位置为窗口的相对位置
#include <iostream>
#include <QtAlgorithms>
#include <QString>
MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent) {
    //加菜单
    QMenuBar *pMenuBar = menuBar();
    QMenu *pmenu = pMenuBar->addMenu("FiveChess");   //增加一个File菜单
    _menu = pmenu;
    //为File菜单增加一个选项,名字open，添加到this窗口，调用一个槽函数，快捷键为Ctrl+O（window系统下）
    QAction *openAction = pmenu->addAction("&restart", this, SLOT(start()), QKeySequence::Open);
    pmenu->addSeparator();      //增加一条线
    QAction *closeAction = pmenu->addAction("&close", this, SLOT(close()), QKeySequence::Close);
    //设置消息提示
    closeAction->setToolTip("close window");
    //增加工具栏,工具栏和菜单栏实质差不多，只不过其表现方式有些不同，而且toolBar是可以浮动的
    QToolBar *toolBar = this->addToolBar("My Tool Bar...");
    toolBar->addAction(openAction);
    toolBar->addAction(closeAction);
    this->setNewArray();
    //托盘,相当于在打开该应用程序的时候再桌面上有一个图标
    _icon = new QSystemTrayIcon;
    _icon->setIcon((QIcon("../icon.ico")));
    _icon->setToolTip("This is icon test");
    _icon->show();
    //将鼠标知道图标的位置会提示消息
    _icon->setContextMenu(_menu);

    //触发图标按钮
    connect(_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotActivated(QSystemTrayIcon::ActivationReason)));

}

void MyMainWindow::setNewArray() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            Pointer *pointer = new Pointer(i, j, 0);
            this->NewArray.push_back(*pointer);
        }
    }
}

void MyMainWindow::paintEvent(QPaintEvent *event) {
    paint = new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::darkGreen, 2, Qt::SolidLine));
    for (int i = 0; i < SIZE + 1; ++i) {
        paint->drawLine(x, y + WIDTH * i, x + WIDTH * (SIZE), y + WIDTH * i);
    }
    for (int i = 0; i < SIZE + 1; i++) {
        paint->drawLine(x + WIDTH * i, y, x + WIDTH * i, y + WIDTH * (SIZE));
    }

    if (!this->BlackChess.empty()) {
        for (auto i = this->BlackChess.begin(); i != this->BlackChess.end(); i++) {
            paint->setBrush(QBrush(Qt::black, Qt::SolidPattern));//毛刷：颜色，实图案
            paint->drawEllipse((*i).x * this->WIDTH + this->x - WIDTH / 4, (*i).y * this->WIDTH + this->y - WIDTH / 4,
                               WIDTH / 2, WIDTH / 2);//画椭圆：中心点X,Y,宽度，高度
        }
    }
    if (!this->WhiteChess.empty()) {
        for (auto i = this->WhiteChess.begin(); i != this->WhiteChess.end(); i++) {
            paint->setBrush(QBrush(Qt::white, Qt::SolidPattern));//毛刷：颜色，实图案
//            cout<<"x:"<<(*i)->x<<"y:"<<(*i)->y<<endl;
            paint->drawEllipse((*i).x * this->WIDTH + this->x - WIDTH / 4, (*i).y * this->WIDTH + this->y - WIDTH / 4,
                               WIDTH / 2, WIDTH / 2);//画椭圆：中心点X,Y,宽度，高度
        }
    }
    for (auto i = this->NewArray.begin(); i != this->NewArray.end(); i++) {
        QFont font;
        font.setPointSize(18);
        paint->drawText((*i).x * this->WIDTH + this->x, (*i).y * this->WIDTH + this->y ,QString::number(i->score));
    }
    paint->end();
}

void MyMainWindow::slotActivated(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) {
        if (this->isHidden()) this->show();
        else this->hide();
    }
}

void MyMainWindow::mousePressEvent(QMouseEvent *ev) {
//此时鼠标跳出的位置是相对于电脑桌面的位置，而不是现对于窗口的位置
    if (this->stoff) {
        double x1 = ev->x() - this->x;
        double y1 = ev->y() - this->y;
        //限制区域
        if (x1 < 0 || y1 < 0) {
            return;
        }
        if (x1 > 15 * this->WIDTH || y1 > 15 * this->WIDTH) {
            return;
        }
        Pointer *pointer = new Pointer(qRound(x1 / this->WIDTH), qRound(y1 / this->WIDTH), 0);
        /**
         * 判断是否有子
         */
        bool isSelf = false;//是否已存在子
        if (!this->WhiteChess.empty()) {
            QVector<Pointer> array;
            array.append(this->WhiteChess);
            array.append(this->BlackChess);
            for (auto i = array.begin(); i != array.end(); i++) {
                if (pointer->x == (*i).x && pointer->y == (*i).y) {
                    isSelf = true;
                }
            }
            if (!isSelf) {
                this->BlackChess.push_back(*pointer);
                this->update();
            }
        } else {
            this->BlackChess.push_back(*pointer);
            this->update();
        }
        /**
         * 判断胜负
         */
        if (!this->win(pointer, 1)) {
            if (!isSelf) {
                this->AIplayer();
            }
            this->update();
        } else {
            this->stoff = false;
            QMessageBox::StandardButton result = QMessageBox::information(NULL, "胜负已分", "黑棋胜",
                                                                          QMessageBox::Yes | QMessageBox::No);
            switch (result) {
                case QMessageBox::Yes:
                    this->start();
                    break;
                case QMessageBox::No:
                    break;
                default:
                    break;
            }

            return;
        }
    }

}

void MyMainWindow::AIplayer() {
/**
 * 写一套AI
 */
    this->step++;
    //简单的AI

    Pointer pointer = this->getBestPointer();
    this->WhiteChess.push_back(pointer);
    if (this->win(&pointer, 0)) {
        this->stoff = false;
        QMessageBox::StandardButton result = QMessageBox::information(NULL, "胜负已分", "白棋胜",
                                                                      QMessageBox::Yes | QMessageBox::No);
        switch (result) {
            case QMessageBox::Yes:
                this->start();
                break;
            case QMessageBox::No:
                break;
            default:
                break;
        }
        return;
    }
}

QVector<Pointer> MyMainWindow::getEmptyArray() {
    QVector<Pointer> existArray;
    QVector<Pointer> emptyArray;
    qDeleteAll(existArray);
    qDeleteAll(emptyArray);
    existArray.clear();
    emptyArray.clear();
    existArray.append(this->WhiteChess);
    existArray.append(this->BlackChess);
    for (auto j = existArray.begin(); j != existArray.end(); j++) {
    for (auto i = this->NewArray.begin(); i != this->NewArray.end(); i++) {

            if ((*j).x == (*i).x && (*j).y == (*i).y) {

            }else{
                emptyArray.push_back(*i);
            }
        }
    }
    cout<<emptyArray.size()<<endl;
    return  emptyArray;
}

bool simpleSort(Pointer a, Pointer b) {
    return a.score > b.score;
}

Pointer MyMainWindow::getBestPointer() {
    QVector<Pointer> emptyArray = this->getEmptyArray();
    QVector<Pointer> emptyList;
    for (auto i = emptyArray.begin(); i != emptyArray.end(); i++) {
        this->sumScore(i);
        for(auto j= this->NewArray.begin();j != this->NewArray.end(); j++){
            if((*i).x==j->x&&(*i).y==j->y){
                j->setScore((*i).score);
            }
        }
        emptyList.push_back(*new Pointer((*i).x,(*i).y,(*i).score));
    }
    this->update();
    qSort(emptyList.begin(), emptyList.end(), simpleSort);
    return emptyList[0];
}

void MyMainWindow::sumScore(Pointer *pointer) {
//    白子算分
    if (this->checkScore(pointer, this->WhiteChess, 0, 1) == 0) {
        pointer->addScore(0);
    } else if (this->checkScore(pointer, this->WhiteChess, 0, 1) == 1) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->WhiteChess, 0, 1) == 2) {
        pointer->addScore(2);
    } else if (this->checkScore(pointer, this->WhiteChess, 0, 1) == 3) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->WhiteChess, 0, 1) == 4) {
        pointer->addScore(4);
    } else if (this->checkScore(pointer, this->WhiteChess, 0, 1) >= 5) {
        pointer->addScore(5);
    }
        if (this->checkScore(pointer, this->WhiteChess, 1, 0) == 0) {
        pointer->addScore(0);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 0) == 1) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 0) == 2) {
        pointer->addScore(2);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 0) == 3) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 0) == 4) {
        pointer->addScore(4);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 0) >= 5) {
        pointer->addScore(5);
    }
            if (this->checkScore(pointer, this->WhiteChess, -1, 1) == 0) {
        pointer->addScore(0);
    } else if (this->checkScore(pointer, this->WhiteChess, -1, 1) == 1) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->WhiteChess, -1, 1) == 2) {
        pointer->addScore(2);
    } else if (this->checkScore(pointer, this->WhiteChess, -1, 1) == 3) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->WhiteChess, -1, 1) == 4) {
        pointer->addScore(4);
    } else if (this->checkScore(pointer, this->WhiteChess, -1, 1) >= 5) {
        pointer->addScore(5);
    }
                if (this->checkScore(pointer, this->WhiteChess, 1, 1) == 0) {
        pointer->addScore(0);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 1) == 1) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 1) == 2) {
        pointer->addScore(2);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 1) == 3) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 1) == 4) {
        pointer->addScore(4);
    } else if (this->checkScore(pointer, this->WhiteChess, 1, 1) >= 5) {
        pointer->addScore(5);
    }
    if (this->checkScore(pointer, this->BlackChess, 0, 1) == 0) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->BlackChess, 0, 1) == 1) {
        pointer->addScore(-2);
    } else if (this->checkScore(pointer, this->BlackChess, 0, 1) == 2) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->BlackChess, 0, 1) >= 3) {
        pointer->addScore(5);
    }
        if (this->checkScore(pointer, this->BlackChess, 1, 0) == 0) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 0) == 1) {
        pointer->addScore(-2);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 0) == 2) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 0) >= 3) {
        pointer->addScore(5);
    }
                if (this->checkScore(pointer, this->BlackChess, -1, 1) == 0) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->BlackChess, -1, 1) == 1) {
        pointer->addScore(-2);
    } else if (this->checkScore(pointer, this->BlackChess, -1, 1) == 2) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->BlackChess, -1, 1) >= 3) {
        pointer->addScore(5);
    };
                if (this->checkScore(pointer, this->BlackChess, 1, 1) == 0) {
        pointer->addScore(1);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 1) == 1) {
        pointer->addScore(-2);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 1) == 2) {
        pointer->addScore(3);
    } else if (this->checkScore(pointer, this->BlackChess, 1, 1) >= 3) {
        pointer->addScore(5);
    }

    //判断三个连续存在算法
    if (this->checkScore(pointer, this->BlackChess, 0, 1, 3) >= 3) {
        pointer->addScore(1);
    }
      if (this->checkScore(pointer, this->BlackChess, 1, 0, 3) >= 3) {
        pointer->addScore(1);
    }
        if (this->checkScore(pointer, this->BlackChess, 1, 1, 3) >= 3) {
        pointer->addScore(1);
    }
          if (this->checkScore(pointer, this->BlackChess, -1, 1, 3) >= 3) {
        pointer->addScore(1);
    }
    if (this->checkScore(pointer, this->BlackChess, 0, 1, 2) >= 1) {
        pointer->addScore(-2);
    }
      if (this->checkScore(pointer, this->BlackChess, 1, 0, 2) >1) {
        pointer->addScore(-2);
    }
        if (this->checkScore(pointer, this->BlackChess, 1, 1, 2) > 1) {
        pointer->addScore(-2);
    }
          if (this->checkScore(pointer, this->BlackChess, -1, 1, 2) > 1) {
        pointer->addScore(-2);
    }
          if (this->checkScore(pointer, this->BlackChess, 0, 1, 3) > 2) {
        pointer->addScore(-2);
    }
      if (this->checkScore(pointer, this->BlackChess, 1, 0, 3) >= 2) {
        pointer->addScore(-2);
    }
        if (this->checkScore(pointer, this->BlackChess, 1, 1, 3) >= 2) {
        pointer->addScore(-2);
    }
          if (this->checkScore(pointer, this->BlackChess, -1, 1, 3) >= 2) {
        pointer->addScore(-2);
    }
}

int MyMainWindow::checkScore(Pointer *pointer, QVector<Pointer> array, int xdiff, int ydiff, int key) {
    Pointer *tmp = new Pointer(0, 0, 0);
    int cnt = 0;
//    cout<<pointer->x<<pointer->y<<endl;
    for (int i = 1; i < key; i++) {
        bool a = false;
        tmp->x = pointer->x - xdiff * i;
        tmp->y = pointer->y - ydiff * i;
        for (auto j = array.begin(); j != array.end(); j++) {
            if ((*j).x == tmp->x && ((*j).y) == tmp->y) {
                a = true;
            }
        }
        if (a) {
            cnt++;
        }
    }
    for (int i = 1; i < key; i++) {
        bool b = false;
        tmp->x = pointer->x + xdiff * i;
        tmp->y = pointer->y + ydiff * i;
        for (auto j = array.begin(); j != array.end(); j++) {
            if ((*j).x == tmp->x && ((*j).y) == tmp->y) {
                b = true;

            }
        }

        if (b) {
            cnt++;
        }
    }
    return cnt;
}

bool MyMainWindow::win(Pointer *pointer, int player) {
    QString play;
    QVector<Pointer> array;
    if (player == 1) {
        play = "黑棋";
        array = this->BlackChess;
    } else {
        play = "白棋";
        array = this->WhiteChess;
    }
    /**
    * 如何判断胜负
    */
    if (this->checkByStep(pointer, array, 0, 1))    //上下直线判断
        return true;
    if (this->checkByStep(pointer, array, 1, 0))    //左右直线判断
        return true;
    if (this->checkByStep(pointer, array, 1, 1))    //右朝上直线判断
        return true;
    if (this->checkByStep(pointer, array, -1, 1))   //右朝下直线判断
        return true;
    return false;
}

bool MyMainWindow::checkByStep(Pointer *pointer, QVector<Pointer> array, int xdiff, int ydiff) {
    if (this->checkScore(pointer, array, xdiff, ydiff) >= 4) {
        return true;
    } else {
        return false;
    }
}

void MyMainWindow::start() {
    //设置开关
    qDeleteAll(this->BlackChess.begin(),this->BlackChess.end());
    this->BlackChess.clear();
    qDeleteAll(this->WhiteChess.begin(),this->WhiteChess.end());
    this->WhiteChess.clear();
    this->stoff = true;
    for (auto j = this->NewArray.begin(); j != this->NewArray.end(); j++) {
        j->setScore(0);
    }

    this->update();
}
