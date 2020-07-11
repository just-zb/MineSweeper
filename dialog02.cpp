#include "dialog02.h"
#include "ui_dialog02.h"

Dialog02::Dialog02(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog02)
{
    ui->setupUi(this);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushButton_4_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushButton_7_clicked()));
}

Dialog02::~Dialog02()
{
    delete ui;
}



void Dialog02::on_pushButton_4_clicked()
{
    emit mvsigsendata_1();
}
void Dialog02::on_pushButton_7_clicked()
{
    emit mvsigsendata_2();
}
