#include "login.h"
#include "ui_login.h"
#include "startwindow.h"

Login::Login(QWidget *parent, StartWindow *start) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->move(560,240);
    startwindow = start;
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_2_clicked()
{
    hide();
    startwindow->show();
}

