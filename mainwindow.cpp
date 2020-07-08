#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "block.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*测试，应该无bug
    block B;
    B.Click(0,0);
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<18;j++)
        {
            qDebug()<<B.GameMap[i][j]<<" ";
        }
        qDebug()<<endl;
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

//绘图事件
void MainWindow::paintEvent(QPaintEvent *event)
{
    //todo
}

//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //点了左键
    if(MouseButtom == 0)
    {
        QPoint P = event->pos();
        //假设扫雷的棋盘从窗口的（30,30）开始，到（390,350）
        //则每个小格的大小是 宽 20 =（390-30）/18，高 20=（350-30）/16
        myBlock.Click((P.x()-30) / 20,(P.y()-30) / 20);
        qDebug() << (P.x()-30) / 20;
    }
    
    //点了右键
    if(MouseButtom == 1)
    {
        //todo
    }

    //更新绘图事件
    update();
}

//鼠标按下事件
void  MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        MouseButtom = 0;
    }
    if(event->button()==Qt::RightButton)
    {
        MouseButtom = 1;
    }
}
