#ifndef DIALOG01_H
#define DIALOG01_H

#include <QDialog>

namespace Ui {
class Dialog01;
}

class Dialog01 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog01(QWidget *parent = 0);
    ~Dialog01();
signals:
    void signal_1();
    void signal_2();
private slots:
    void on_pushBotton_clicked();
    void on_pushBotton_2_clicked();
private:
    Ui::Dialog01 *ui;
};

#endif // DIALOG01_H
