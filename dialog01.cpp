#include "dialog01.h"
#include "ui_dialog01.h"

Dialog01::Dialog01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog01)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
}

Dialog01::~Dialog01()
{
    delete ui;
}
void Dialog01::on_pushBotton_clicked()
{
    emit signal_1();
}
void Dialog01::on_pushBotton_2_clicked()
{
    emit signal_2();
}
