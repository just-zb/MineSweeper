#include "dialog01.h"
#include "ui_dialog01.h"
#include<QSound>

Dialog01::Dialog01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog01)
{
    ui->setupUi(this);
    connect(ui->dialog_1_pushButton,SIGNAL(clicked()),this,SLOT(on_1_pushButton_clicked()));
    connect(ui->dialog_1_pushButton_2,SIGNAL(clicked()),this,SLOT(on_1_pushButton_2_clicked()));
}

Dialog01::~Dialog01()
{
    delete ui;
}
void Dialog01::on_1_pushButton_clicked()//dialog01上的重新来一盘按钮，点击就发送一个信号，下同
{   QSound *sound_push_5_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_5_button->play();
    emit mvsigsendata_1();

}
void Dialog01::on_1_pushButton_2_clicked()//退出游戏按钮
{   QSound *sound_push_6_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_6_button->play();
    emit  mvsigsendata_2();

}
