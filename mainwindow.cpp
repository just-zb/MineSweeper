
#include<Qpainter>
#include<QTimer>
#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "block.h"
#include<QImage>
#include<QPixmap>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    //关联信号槽
       connect(kTimer,SIGNAL(timeout()),this,SLOT(on_lcdNumber_2_overflow()));//flag
       connect(mTimer,SIGNAL(timeout()),this,SLOT(on_lcdNumber_overflow()));//gametime
       connect(mTimer,SIGNAL(timeout()),this,SLOT(updateGameTime()));//开始游戏
}



MainWindow::~MainWindow()

{

    delete ui;

}


void MainWindow::paintEvent(QPaintEvent *event)

{   int flag=0;
    QPixmap img01(":/flag01.png");
    QPixmap img02(":/mine.png");



QPainter p(this);
p.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置主窗口背景色调为白色
p.drawRect(0,0,400,400);//使用上面的白色笔刷来绘制该像素区（x,y,wideth,height)
p.fillRect(30,55,360,280,Qt::blue);//填充该像素区，和上面一种函数大同小异
QFont font1;//设置字体
font1.setPixelSize(15);//字体大小
font1.setLetterSpacing(QFont::AbsoluteSpacing,0);


p.setFont(font1);//使用字体
for(int i=0;i<14;i++)
{   for(int j=0;j<18;j++)
    {   if(myBlock.GameMap[i][j]==199)
            flag=1;
    }
}
if(flag==1)
{   for(int i=0;i<14;i++)//测试时，用黑色显示地雷的位置，解决递归问题和贴图问题后用贴图代替
    {   for(int j=0;j<18;j++)
        {   if(myBlock.GameMap[i][j]==199)
            {  for(int k=0;k<14;k++)
               {    for(int l=0;l<18;l++)
                    {   if(myBlock.GameMap[k][l]==199||myBlock.GameMap[k][l]==99||myBlock.GameMap[k][l]==149)
                        {   myBlock.GameMap[k][l]=199;
                            p.drawPixmap(30+l*20,55+k*20,img02,0,0,20,20);
                        }
                    }
               }
                p.drawText(30,390,tr("Game Over"));


            }




        }
    }

}

//p.drawPixmap(0,0,30,30,flagimage);
    for(int i=0;i<14;i++)//显示数字
    {   for(int j=0;j<18;j++)
        {   if(myBlock.GameMap[i][j]>=100&&myBlock.GameMap[i][j]<110)
            { p.fillRect(30+j*20,55+i*20,20,20,Qt::gray);
                if(myBlock.GameMap[i][j]==101)
                {   p.setPen(Qt::black);//设置不同数字对应的颜色
                    p.drawText(30+j*20,70+i*20,tr(" 1"));}
                else if(myBlock.GameMap[i][j]==102)
                {   p.setPen(Qt::yellow);
                    p.drawText(30+j*20,70+i*20,tr(" 2"));}
                else if(myBlock.GameMap[i][j]==103)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 3"));}
                else if(myBlock.GameMap[i][j]==104)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 4"));}
                else if(myBlock.GameMap[i][j]==105)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 5"));}
                else if(myBlock.GameMap[i][j]==106)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 6"));}
                else if(myBlock.GameMap[i][j]==107)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 7"));}
                else if(myBlock.GameMap[i][j]==108)
                {   p.setPen(Qt::red);
                    p.drawText(30+j*20,70+i*20,tr(" 8"));}
                else if(myBlock.GameMap[i][j]==100)
                    p.drawText(30+j*20,70+i*20,tr("  "));
            }
        }
    }
/*   for(int i=0;i<14;i++)//测试时显示数字
    {   for(int j=0;j<18;j++)
        {   if(myBlock.GameMap[i][j]<100)
            {
                if(myBlock.GameMap[i][j]==1)
                    p.drawText(30+j*20,70+i*20,tr(" 1"));
                else if(myBlock.GameMap[i][j]==2)
                    p.drawText(30+j*20,70+i*20,tr(" 2"));
                else if(myBlock.GameMap[i][j]==3)
                    p.drawText(30+j*20,70+i*20,tr(" 3"));
                else if(myBlock.GameMap[i][j]==4)
                    p.drawText(30+j*20,70+i*20,tr(" 4"));
                else if(myBlock.GameMap[i][j]==5)
                    p.drawText(30+j*20,70+i*20,tr(" 5"));
                else if(myBlock.GameMap[i][j]==6)
                    p.drawText(30+j*20,70+i*20,tr(" 6"));
                else if(myBlock.GameMap[i][j]==7)
                    p.drawText(30+j*20,70+i*20,tr(" 7"));
                else if(myBlock.GameMap[i][j]==8)
                    p.drawText(30+j*20,70+i*20,tr(" 8"));
                else if(myBlock.GameMap[i][j]==0)
                    p.drawText(30+j*20,70+i*20,tr(" 0"));
               }
        }
    }*/


  /*  for(int i=0;i<14;i++)//贴图用，未起作用
    {   for(int j=0;j<18;j++)
        {   if(myBlock.GameMap[i][j]>=50&&myBlock.GameMap[i][j]<=58)
                p.drawImage(30+j*20,50+i*20,img01);
        }
    }*/
  /*  for(int i=0;i<14;i++)//鼠标左键点击后变为1000，测试用
    {   for(int j=0;j<18;j++)
        {   if(myBlock.GameMap[i][j]==1000)
               p.fillRect(30+j*20,30+i*20,20,20,Qt::gray);
       }
    }*/
    for(int i=0;i<14;i++)//鼠标右键点击后变为900，测试用
    {   for(int j=0;j<18;j++)
        {   if((myBlock.GameMap[i][j]>=50&&myBlock.GameMap[i][j]<=58)||myBlock.GameMap[i][j]==149)
            {


                p.drawPixmap(30+j*20,55+i*20,img01,0,0,20,20);

             // p.fillRect(30+j*20,55+i*20,20,20,Qt::yellow);
             }
       }
    }

}



//鼠标释放时才进行操作，避免按着不放的情况发生，

//查资料后删除了mouseMoveEvent，直接在这里返回释放时的鼠标位置。

void  MainWindow::mouseReleaseEvent(QMouseEvent *event)

{
    //打开计时器
    mTimer->start(1000);
    kTimer->start(0);

    //释放了左键
QPoint P = event->pos();
    if(event->button()==Qt::LeftButton)

    {
        myBlock.Click((P.y()-50) / 20,(P.x()-30) / 20);    //<<<<<<<<这里改了一下，调了下行列的位置，原来的是错的
        qDebug() << (P.x()-30) / 20 <<" "<< (P.y()-50) / 20<<" "<<myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20];
        handleGameState();
    }
    //释放了右键
    if(event->button()==Qt::RightButton)
    {
        if((myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]>=0&&myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]<=8)||myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]==99)
            myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]+=50;
        else if((myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]>=50&&myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]<=58)||myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]==149)
            myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20]-=50;
        handleGameState();
    }
}
void MainWindow::updateGameTime()
{
    myBlock.GameTime++;
    qDebug()<<myBlock.GameTime;
}
//处理游戏状态的函数
void MainWindow::handleGameState()
{
    myBlock.Win();
    if(myBlock.gamestate == WIN)
    {
        mTimer->stop();
        qDebug()<<"你赢了！";
       // myBlock.restartGame();
        dialog01=new Dialog01(this);
        dialog01->setModal(false);
        dialog01->resize(300,300);
        dialog01->show();
        connect(dialog01,SIGNAL(mvsigsendata_1()),this,SLOT(on_dialog_1_pushButton_clicked()));
        connect(dialog01,SIGNAL(mvsigsendata_2()),this,SLOT(on_dialog_1_pushButton_2_clicked()));
        //delete dialog01;
    }
    else if(myBlock.gamestate==OVER)
    {
        mTimer->stop();
        qDebug()<<"你输了！";

        //myBlock.restartGame();
        dialog02=new Dialog02(this);
        dialog02->setModal(false);
        dialog02->resize(150,200);
        dialog02->show();
 //       connect(dialog02,SIGNAL(mvsigsendata()),this,SLOT(on_pushButton_5_clicked));
        connect(dialog02,SIGNAL(mvsigsendata_1()),this,SLOT(on_dialog_2_pushButton_clicked()));//子窗口的再来一盘实现再来一盘
        connect(dialog02,SIGNAL(mvsigsendata_2()),this,SLOT(on_dialog_2_pushButton_2_clicked()));//子窗口的退出游戏实现退出游戏

        //delete dialog02;
    }
    update();
}
void MainWindow::on_dialog_1_pushButton_clicked()
{
    delete dialog01;
    myBlock.restartGame();
    qDebug()<<"success";
    update();

}
void MainWindow::on_dialog_1_pushButton_2_clicked()
{
    delete dialog01;
     QCoreApplication::quit();


}
void MainWindow::on_dialog_2_pushButton_clicked()
{
    delete dialog02;
    myBlock.restartGame();
    qDebug()<<"success";
    update();

}
void MainWindow::on_dialog_2_pushButton_2_clicked()
{
    delete dialog02;
     QCoreApplication::quit();


}

//开始游戏的槽
void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"重新开始";
    myBlock.restartGame();
    //更新游戏绘图
    update();
}
//退出游戏的槽函数
void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"退出游戏";
    QCoreApplication::quit();
}
//显示红旗数目的槽函数
void MainWindow::on_lcdNumber_2_overflow()
{
    //对lcdnumber时间的显示样式做出修改
    myBlock.FlagNumber();
    // 设置位数
    ui->lcdNumber_2->setDigitCount(4);
    // 设置显示外观
    ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    ui->lcdNumber_2->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    ui->lcdNumber_2->display(myBlock.Flag);


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
    ui->lcdNumber->display(myBlock.GameTime);
}
