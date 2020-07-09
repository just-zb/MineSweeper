
#include<Qpainter>
#include<QTimer>
#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "block.h"
#include<QImage>
#include<QPixmap>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    //设置计时器
    mTimer->setInterval(1000);
    //关联信号槽
        connect(mTimer,SIGNAL(timeout()),this,on_lcdNumber_2_overflow(););
        connect(mTimer,SIGNAL(timeout()),this,on_lcdNumber_overflow(););

}



MainWindow::~MainWindow()

{

    delete ui;

}


void MainWindow::paintEvent(QPaintEvent *event)

{
    QPixmap flagimage;
    flagimage.load(":/Resources/new/prefix1/flag.jpg");//原本用于贴图


QPainter p(this);
p.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置主窗口背景色调为白色
p.drawRect(0,0,400,400);//使用上面的白色笔刷来绘制该像素区（x,y,wideth,height)
p.fillRect(30,30,360,280,Qt::blue);//填充该像素区，和上面一种函数大同小异
QFont font1;//设置字体
font1.setPixelSize(15);//字体大小
font1.setLetterSpacing(QFont::AbsoluteSpacing,0);

p.setFont(font1);//使用字体
for(int i=0;i<14;i++)//测试时，用黑色显示地雷的位置，解决递归问题和贴图问题后用贴图代替
{   for(int j=0;j<18;j++)
    {   if(bl.GameMap[i][j]==99)
            p.fillRect(30+j*20,30+i*20,20,20,Qt::black);
   }
}

//p.drawPixmap(0,0,30,30,flagimage);
    for(int i=0;i<14;i++)//显示数字
    {   for(int j=0;j<18;j++)
        {   if(bl.GameMap[i][j]>=100&&bl.GameMap[i][j]<500)
                 p.fillRect(30+j*20,30+i*20,20,20,Qt::gray);
                if(bl.GameMap[i][j]==101)
                    p.drawText(30+j*20,50+i*20,tr(" 1"));
                else if(bl.GameMap[i][j]==102)
                    p.drawText(30+j*20,50+i*20,tr(" 2"));
                else if(bl.GameMap[i][j]==103)
                    p.drawText(30+j*20,50+i*20,tr(" 3"));
                else if(bl.GameMap[i][j]==104)
                    p.drawText(30+j*20,50+i*20,tr(" 4"));
                else if(bl.GameMap[i][j]==105)
                    p.drawText(30+j*20,50+i*20,tr(" 5"));
                else if(bl.GameMap[i][j]==106)
                    p.drawText(30+j*20,50+i*20,tr(" 6"));
                else if(bl.GameMap[i][j]==107)
                    p.drawText(30+j*20,50+i*20,tr(" 7"));
                else if(bl.GameMap[i][j]==108)
                    p.drawText(30+j*20,50+i*20,tr(" 8"));
        }
    }
    for(int i=0;i<14;i++)//测试时显示数字
    {   for(int j=0;j<18;j++)
        {   if(bl.GameMap[i][j]<100)
            {
                if(bl.GameMap[i][j]==1)
                    p.drawText(30+j*20,50+i*20,tr(" 1"));
                else if(bl.GameMap[i][j]==2)
                    p.drawText(30+j*20,50+i*20,tr(" 2"));
                else if(bl.GameMap[i][j]==3)
                    p.drawText(30+j*20,50+i*20,tr(" 3"));
                else if(bl.GameMap[i][j]==4)
                    p.drawText(30+j*20,50+i*20,tr(" 4"));
                else if(bl.GameMap[i][j]==5)
                    p.drawText(30+j*20,50+i*20,tr(" 5"));
                else if(bl.GameMap[i][j]==6)
                    p.drawText(30+j*20,50+i*20,tr(" 6"));
                else if(bl.GameMap[i][j]==7)
                    p.drawText(30+j*20,50+i*20,tr(" 7"));
                else if(bl.GameMap[i][j]==8)
                    p.drawText(30+j*20,50+i*20,tr(" 8"));
               }
        }
    }

    for(int i=0;i<14;i++)//贴图用，未起作用
    {   for(int j=0;j<18;j++)
        {   if(bl.GameMap[i][j]>=50&&bl.GameMap[i][j]<=58)
                p.drawPixmap(30+j*20,50+i*20,flagimage);
        }
    }
    for(int i=0;i<14;i++)//鼠标左键点击后变为1000，测试用
    {   for(int j=0;j<18;j++)
        {   if(bl.GameMap[i][j]==1000)
               p.fillRect(30+j*20,30+i*20,20,20,Qt::gray);
       }
    }
    for(int i=0;i<14;i++)//鼠标右键点击后变为900，测试用
    {   for(int j=0;j<18;j++)
        {   if(bl.GameMap[i][j]==900)
               p.fillRect(30+j*20,30+i*20,20,20,Qt::yellow);
       }
    }
    
}



//鼠标释放时才进行操作，避免按着不放的情况发生，

//查资料后删除了mouseMoveEvent，直接在这里返回释放时的鼠标位置。

void  MainWindow::mouseReleaseEvent(QMouseEvent *event)

{

    //释放了左键
QPoint P = event->pos();
    if(event->button()==Qt::LeftButton)

    {

    if(bl.GameMap[(P.y()-30) / 20][(P.x()-30) / 20]==0)
    bl.GameMap[(P.y()-30) / 20][(P.x()-30) / 20]=1000;
        //假设扫雷的棋盘从窗口的（30,30）开始，到（390,350）
        //则每个小格的大小是 宽 20 =（390-30）/18，高 20=（310-30）/14

        bl.Click((P.y()-30) / 20,(P.x()-30) / 20);                                             //<<<<<<<<这里改了一下，调了下行列的位置，原来的是错的

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

    {if(bl.GameMap[(P.y()-30) / 20][(P.x()-30) / 20]==0)
            bl.GameMap[(P.y()-30) / 20][(P.x()-30) / 20]=900;

        //todo

    }
    //更新绘图事件
    update();
}
//开始游戏的槽
void MainWindow::on_pushButton_clicked()
{
    //在点击开始游戏后，开始计时器。
    mTimer->start();
    //重新定义bl对象
    block mbl;
    bl=mbl;
}
//退出游戏的槽函数
void MainWindow::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}
void MainWindow::on_lcdNumber_2_overflow()
{
    //对lcdnumber时间的显示样式做出修改
    // 设置位数
    ui->lcdNumber_2->setDigitCount(4);
    // 设置显示外观
    ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    ui->lcdNumber_2->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber_2->display(0);


}

void MainWindow::on_lcdNumber_overflow()
{
    //对lcdnumber时间的显示样式做出修改
    // 设置位数
    ui->lcdNumber->setDigitCount(4);
    // 设置显示外观
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    ui->lcdNumber->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber->display(0);
}
