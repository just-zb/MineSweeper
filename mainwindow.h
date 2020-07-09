#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//游戏界面
#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include "block.h"
#include<QPaintEvent>

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

    block bl;

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
    //定义m_pLCD来展示时间
    QLCDNumber m_pLCD = new QLCDNumber(this);
    //放置定时器实现LCD的每秒刷新
    QTimer* mTimer=new QTimer(this);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_lcdNumber_2_overflow();
    void on_lcdNumber_overflow();
};

#endif // MAINWINDOW_H
