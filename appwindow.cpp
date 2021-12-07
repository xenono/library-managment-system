#include "appwindow.h"
#include "ui_appwindow.h"
#include "profilepage.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->move(320,180);
    profilePage = new ProfilePage(this);
    profilePage->move(0,150);
    profilePage->hide();
}

void AppWindow::SetLoggedUser(QString username, QString password, QString userType){
    Username = username;
    Password = password;
    UserType = userType;
}

AppWindow::~AppWindow()
{
    delete ui;
}

void AppWindow::on_pushButton_2_clicked()
{
    profilePage->SetUserInfo(Username,Email,UserType);
    profilePage->show();
}

