#include "dialog02.h"
#include "ui_dialog02.h"
#include<QSound>

Dialog02::Dialog02(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog02)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_2_pushButton_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_2_pushButton_2_clicked()));
}

Dialog02::~Dialog02()
{
    delete ui;
}

void Dialog02::on_2_pushButton_clicked()//dialog02上的再来一盘的按钮。点击发送信号，下同
{   QSound *sound_push_3_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_3_button->play();
    emit mvsigsendata_1();
}
void Dialog02::on_2_pushButton_2_clicked()//dialog02上的退出游戏按钮
{   QSound *sound_push_4_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_4_button->play();
    emit mvsigsendata_2();
}
