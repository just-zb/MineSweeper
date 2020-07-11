#ifndef DIALOG03_H
#define DIALOG03_H

#include <QDialog>
#include<QSpinBox>

namespace Ui {
class Dialog03;
}

class Dialog03 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog03(QWidget *parent = 0);
    ~Dialog03();


private slots:


    void on_dialog_3_pushButton_2_clicked();

    void on_dialog_3_pushButton_clicked();


signals:
    void signal03(int r,int c,int m);

private:
    Ui::Dialog03 *ui;
};

#endif // DIALOG03_H
