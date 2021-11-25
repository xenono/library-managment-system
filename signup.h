#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>
#include "startwindow.h"
namespace Ui {
class SignUp;
}

class SignUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr,StartWindow *start = nullptr);
    ~SignUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SignUp *ui;
    StartWindow *startwindow;
};

#endif // SIGNUP_H
