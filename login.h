#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "startwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr, StartWindow *start = nullptr);
    ~Login();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    StartWindow *startwindow;
};

#endif // LOGIN_H
