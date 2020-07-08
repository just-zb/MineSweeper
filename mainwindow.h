#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//游戏界面
#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include "block.h"

namespace Ui {
class MainWindow;
}
//class block;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    block myBlock;

    //定义处理鼠标移动的函数
    //void MouseEvent(QMouseEvent*m);

    //获取鼠标释放时的位置
    void mouseReleaseEvent(QMouseEvent*event);
    //定义获取当前地图状况的函数
    void CurrentMap(block*b);
    //绘制界面函数
    void paintEvent(QPaintEvent*event);

private:
    Ui::MainWindow *ui;
private slots:


};

#endif // MAINWINDOW_H
