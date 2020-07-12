#include "dialog03.h"
#include "ui_dialog03.h"
#include<QDebug>
#include<QSound>

Dialog03::Dialog03(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog03)
{
    ui->setupUi(this);


}

Dialog03::~Dialog03()
{
    delete ui;
}

void Dialog03::on_dialog_3_pushButton_2_clicked()//重置lineedit按钮
{   QSound *sound_push_1_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_1_button->play();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}





void Dialog03::on_dialog_3_pushButton_clicked()//确定并且获取lineedit内容的按钮，并且发送信号
{   QSound *sound_push_2_button=new QSound(":/按钮点击音效.wav",this);
    sound_push_2_button->play();
    int get_row=14;
    int get_col=18;
    int get_num_mine=40;


    get_row=ui->lineEdit->text().toInt();//用于得到lineedit中用户输入的数据，以下两个同理


   get_col=ui->lineEdit_2->text().toInt();

    get_num_mine=ui->lineEdit_3->text().toInt();




    emit signal03(get_row,get_col,get_num_mine);//发送信号
    qDebug()<<get_row<<" "<<get_col<<" "<<get_num_mine;
}







