#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "block.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //todo
}

//鼠标释放时才进行操作，避免按着不放的情况发生，
//查资料后删除了mouseMoveEvent，直接在这里返回释放时的鼠标位置。
void  MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    //释放了左键
    if(event->button()==Qt::LeftButton)
    {
        QPoint P = event->pos();
        //假设扫雷的棋盘从窗口的（30,30）开始，到（390,350）
        //则每个小格的大小是 宽 20 =（390-30）/18，高 20=（350-30）/16
        myBlock.Click((P.x()-30) / 20,(P.y()-30) / 20);
        qDebug() << (P.x()-30) / 20 <<" "<< (P.y()-30) / 20;
        /*测试
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<18;j++)
            {
                qDebug()<<myBlock.GameMap[i][j]<<" ";
            }
            qDebug()<<endl;
        }
        */
    }

    //释放了右键
    if(event->button()==Qt::RightButton)
    {
        //todo
    }

    //更新绘图事件
    update();
}
