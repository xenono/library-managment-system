#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent,StartWindow *start) :
    QMainWindow(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->move(560,240);
    startwindow = start;
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{

}


void SignUp::on_pushButton_2_clicked()
{
    hide();
    startwindow->show();
}

