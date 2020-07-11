#include "dialog02.h"
#include "ui_dialog02.h"

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
{
    emit mvsigsendata_1();
}
void Dialog02::on_2_pushButton_2_clicked()//dialog02上的退出游戏按钮
{
    emit mvsigsendata_2();
}
