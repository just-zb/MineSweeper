#ifndef DIALOG02_H
#define DIALOG02_H

#include <QDialog>

namespace Ui {
class Dialog02;
}

class Dialog02 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog02(QWidget *parent = 0);
    ~Dialog02();
signals:
    void mvsigsendata_1();
    void mvsigsendata_2();

private slots:


    void on_2_pushButton_clicked();
    void on_2_pushButton_2_clicked();

private:
    Ui::Dialog02 *ui;
};

#endif // DIALOG02_H
