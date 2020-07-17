
#include<Qpainter>
#include<QTimer>
#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "block.h"
#include<QImage>
#include<QPixmap>
#include<QFrame>
#include<QSound>

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    //关联信号槽
       connect(kTimer,SIGNAL(timeout()),this,SLOT(on_lcdNumber_2_overflow()));//flag
       connect(kTimer,SIGNAL(timeout()),this,SLOT(on_lcdNumber_overflow()));//gametime
       connect(mTimer,SIGNAL(timeout()),this,SLOT(updateGameTime()));//开始游戏
}

MainWindow::~MainWindow()

{

    delete ui;

}

void MainWindow::paintEvent(QPaintEvent *event)

{   int flag=0;
    QPixmap img01(":/flag01.png");//用于加载图片，旗子和地雷
    QPixmap img02(":/mine.png");

QPainter p(this);//创建一个对象
p.setBrush(QBrush(Qt::white,Qt::SolidPattern));//设置主窗口背景色调为白色
p.drawRect(0,0,400,400);//使用上面的白色笔刷来绘制该像素区（x,y,wideth,height)
p.fillRect(30,55,myBlock.col*20,myBlock.row*20,Qt::blue);//填充该像素区，和上面一种函数大同小异
QFont font1;//设置字体
font1.setPixelSize(15);//字体大小
font1.setLetterSpacing(QFont::AbsoluteSpacing,0);

p.setFont(font1);//使用字体

for(int i=0;i<myBlock.row;i++)//用于检测是否有雷被翻开
{   for(int j=0;j<myBlock.col;j++)
    {   if(myBlock.GameMap[i][j]==199)
            flag=1;
    }
}
if(flag==1)//如果有雷被翻开，就把地图上所有的雷翻开
{   //添加地雷炸掉的音效
    //QSound*sound_mine=new QSound(":/爆炸.wav",this);
   // sound_mine->play();


    for(int i=0;i<myBlock.row;i++)
    {   for(int j=0;j<myBlock.col;j++)
        {   if(myBlock.GameMap[i][j]==199)
            {  for(int k=0;k<myBlock.row;k++)
               {    for(int l=0;l<myBlock.col;l++)
                    {   if(myBlock.GameMap[k][l]==199||myBlock.GameMap[k][l]==99||myBlock.GameMap[k][l]==149)
                        {   myBlock.GameMap[k][l]=199;
                            p.drawPixmap(30+l*20,55+k*20,img02,0,0,20,20);
                        }
                    }
               }
            }
        }
    }
   // sound_mine->stop();
}


    for(int i=0;i<myBlock.row;i++)//用于在翻开后显示数字
    {   for(int j=0;j<myBlock.col;j++)
        {   if(myBlock.GameMap[i][j]>=100&&myBlock.GameMap[i][j]<110)
            { p.fillRect(30+j*20,55+i*20,20,20,Qt::gray);//设置翻开的方块为灰色
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

    for(int i=0;i<myBlock.row;i++)//鼠标右键点击后显示插旗子的效果
    {   for(int j=0;j<myBlock.col;j++)
        {   if((myBlock.GameMap[i][j]>=50&&myBlock.GameMap[i][j]<=58)||myBlock.GameMap[i][j]==149)
            {
                p.drawPixmap(30+j*20,55+i*20,img01,0,0,20,20);//进行旗子贴图
             }
       }
    }
    for(int i=0;i<=myBlock.row;i++)//绘制矩形框，并且根据设置的大小来绘制矩形框
    {

//绘制横线
        p.setPen(Qt::white);//设置笔刷颜色
        p.drawLine(30,55+i*20,30+myBlock.col*20,55+i*20);//用一黑一白来画线，达到阴影效果
        p.setPen(Qt::black);
        p.drawLine(30,56+i*20,30+myBlock.col*20,56+i*20);

    }
//绘制竖线，原理同上
    for(int j=0;j<=myBlock.col;j++)
    {

       p.setPen(Qt::white);
       p.drawLine(30+j*20,55,30+j*20,55+myBlock.row*20);
       p.setPen(Qt::black);
       p.drawLine(31+j*20,55,31+j*20,55+myBlock.row*20);

    }

}


//鼠标释放时才进行操作，避免按着不放的情况发生，

void  MainWindow::mouseReleaseEvent(QMouseEvent *event)

{
    //打开计时器
    mTimer->start(1000);
    kTimer->start(0);

    //释放了左键
QPoint P = event->pos();
    if(event->button()==Qt::LeftButton)

    {   QSound*sound_push_Gamemap=new QSound(":/点击棋盘音效.wav",this);
        sound_push_Gamemap->play();
        myBlock.Click((P.y()-50) / 20,(P.x()-30) / 20,myBlock.row,myBlock.col);    //<<<<<<<<这里改了一下，调了下行列的位置，原来的是错的
        qDebug() << (P.x()-30) / 20 <<" "<< (P.y()-50) / 20<<" "<<myBlock.GameMap[(P.y()-50) / 20][(P.x()-30) / 20];
        handleGameState();
    }

    //释放了右键
    if(event->button()==Qt::RightButton)
    {   QSound*sound_flag=new QSound(":/插旗子音效.wav",this);
        sound_flag->play();
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
    myBlock.Win(myBlock.row,myBlock.col,myBlock.num_of_mine);
    if(myBlock.gamestate == WIN)
    {
        mTimer->stop();
        qDebug()<<"你赢了！";

        dialog01=new Dialog01(this);//在达到胜利状态时，弹出提示胜利的窗口
        dialog01->setModal(false);
        dialog01->resize(300,300);
        dialog01->show();
        connect(dialog01,SIGNAL(mvsigsendata_1()),this,SLOT(on_dialog_1_pushButton_clicked()));//将子窗口的再来一盘信号和下面的一个槽连接起来
        connect(dialog01,SIGNAL(mvsigsendata_2()),this,SLOT(on_dialog_1_pushButton_2_clicked()));//将子窗口的退出游戏信号和下面的一个槽连接起来
        //delete dialog01;
    }
    else if(myBlock.gamestate==OVER)
    {
        mTimer->stop();
        qDebug()<<"你输了！";
        QSound*sound_mine=new QSound(":/爆炸.wav",this);
        sound_mine->play();

        dialog02=new Dialog02(this);//游戏输掉的状态，弹出提示 游戏输掉的子窗口，其余大致同上
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
void MainWindow::on_dialog_1_pushButton_clicked()//用于实现子窗口1的再来一盘
{
    delete dialog01;
    myBlock.restartGame(myBlock.row,myBlock.col,myBlock.MineNumber);
    qDebug()<<"success";
    update();

}
void MainWindow::on_dialog_1_pushButton_2_clicked()//用于实现子窗口1的退出游戏
{
    delete dialog01;
     QCoreApplication::quit();


}
void MainWindow::on_dialog_2_pushButton_clicked()//用于实现子窗口2的再来一盘
{
    delete dialog02;
    myBlock.restartGame(myBlock.row,myBlock.col,myBlock.MineNumber);
    qDebug()<<"success";
    update();

}
void MainWindow::on_dialog_2_pushButton_2_clicked()//用于实现子窗口2的退出游戏
{
    delete dialog02;
     QCoreApplication::quit();


}
void MainWindow::on_dialog_3_pushButton_clicked(int r,int c,int m)//用于实现子窗口3（也就是修改游戏棋盘大小的窗口）点击确定时主窗口重新绘制
{
    qDebug()<<"这个被点击了";

    myBlock.restartGame(r, c,  m);


    delete dialog03;
}

//开始游戏的槽
void MainWindow::on_pushButton_clicked()
{   QSound *sound_push_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_button->play();;
    qDebug()<<"重新开始";
    myBlock.restartGame(myBlock.row,myBlock.col,myBlock.MineNumber);
    //更新游戏绘图
    update();
}
//退出游戏的槽函数
void MainWindow::on_pushButton_2_clicked()
{   QSound *sound_push_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_button->play();;
    qDebug()<<"退出游戏";
    QCoreApplication::quit();
}
//显示红旗数目的槽函数
void MainWindow::on_lcdNumber_2_overflow()
{
    //对lcdnumber时间的显示样式做出修改
    myBlock.FlagNumber(myBlock.row,myBlock.col,myBlock.num_of_mine);
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
void MainWindow::on_pushButton_3_clicked()//创建子窗口3（也就是修改游戏棋盘大小的窗口）并且连接信号
{   QSound *sound_push_7_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_7_button->play();
    dialog03=new Dialog03(this);
    dialog03->setModal(false);
    dialog03->show();

    connect(dialog03,SIGNAL(signal03(int,int,int)),this,SLOT(on_dialog_3_pushButton_clicked(int,int,int)));

    qDebug()<<"信号传递";
}
