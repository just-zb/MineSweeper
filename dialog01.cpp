#include "dialog01.h"
#include "ui_dialog01.h"

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
void Dialog01::on_1_pushButton_clicked()
{
    emit mvsigsendata_1();

}
void Dialog01::on_1_pushButton_2_clicked()
{
    emit  mvsigsendata_2();

}
