//
// Created by Administrator on 2020/9/18 0018.
//

#ifndef FIVECHESS_MYMAINWINDOW_H
#define FIVECHESS_MYMAINWINDOW_H

#include <QMainWindow>
#include<QSystemTrayIcon>   //系统托盘图标
#include <QPainter>
#include <QDesktopWidget>
#include"QMouseEvent"
#include "pointer.h"
#include <QtMath>
#include <list>
#include <QMessageBox>
using namespace std;
class MyMainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);
    QMenu *_menu;
    QSystemTrayIcon *_icon;      //托盘
    QDesktopWidget dw;
    void mousePressEvent(QMouseEvent *);
    const int SIZE=14;
    const int WIDTH=(dw.height()-80)/SIZE;
    const int x=(dw.width()-dw.height()+80)/2,y=60;
    int step=0;
    QVector<Pointer> WhiteChess;//全部白棋子
    QVector<Pointer> BlackChess;//全部黑棋子
    void paintEvent(QPaintEvent *event);
    void  AIplayer();
    bool win(Pointer *pointer,int player);
    bool checkByStep(Pointer *pointer,QVector<Pointer> list,int xdiff, int ydiff);
    bool stoff= false;
    QVector<Pointer> NewArray;
    void setNewArray();
    int checkScore(Pointer *pointer, QVector<Pointer> array, int xdiff, int ydiff,int key=5);
    void sumScore(Pointer *pointer);
    Pointer getBestPointer();
    QVector<Pointer> getEmptyArray();
signals:
public slots:
//    void slotOpen();
    void start();
    void slotActivated(QSystemTrayIcon::ActivationReason);
private:
    QPainter *paint;
};

#endif //FIVECHESS_MYMAINWINDOW_H
