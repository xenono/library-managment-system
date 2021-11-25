#include "startwindow.h"
#include "ui_startwindow.h"
#include "login.h"
#include "signup.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    this->move(560,240);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    hide();
    Login *loginWindow = new Login(nullptr, this);
    loginWindow->show();
}

void StartWindow::on_pushButton_2_clicked()
{
   hide();
   SignUp *signupWindow = new SignUp(nullptr, this);
   signupWindow->show();

}





