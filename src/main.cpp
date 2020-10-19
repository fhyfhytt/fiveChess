//main.cpp
#include <QApplication>
#include "MyMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyMainWindow w;
    w.setWindowTitle("MyMainWindow");
    w.showFullScreen();
    w.show();
    app.exec();
}