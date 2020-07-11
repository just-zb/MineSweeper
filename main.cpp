#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    block size;
    w.show();
    w.resize(400,400);

    return a.exec();
}
