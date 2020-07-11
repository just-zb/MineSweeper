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
#include<QLCDNumber>
#include<QTimer>
#include<QDialog>
#include"dialog01.h"
#include"dialog02.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    block myBlock;//此处为myBlock
    //获取鼠标释放时的位置
    void mouseReleaseEvent(QMouseEvent*event);
    //定义获取当前地图状况的函数
    void CurrentMap(block*b);
    //绘制界面函数
    void paintEvent(QPaintEvent*event);
    void handleGameState();
private:
    Ui::MainWindow *ui;
    //放置定时器实现GameTime和红旗的数目的每秒刷新
    QTimer *mTimer=new QTimer(this);
    QTimer *kTimer=new QTimer(this);
    Dialog01 *dialog01;
    Dialog02 *dialog02;
public slots:
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_dialog_1_pushButton_5_clicked();
    void on_dialog_1_pushButton_6_clicked();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_lcdNumber_2_overflow();
    void on_lcdNumber_overflow();
    void updateGameTime();//更新时间
};

#endif // MAINWINDOW_H

