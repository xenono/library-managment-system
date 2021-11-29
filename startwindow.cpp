#include "startwindow.h"
#include "startpage.h"
#include "loginpage.h"
#include "signuppage.h"
#include "ui_startwindow.h"
#include "appwindow.h"

StartWindow::StartWindow(QWidget *parent, AppWindow *appWindowPointer)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    this->move(560,240);
    appWindow = appWindowPointer;
    appWindow->hide();
    startPage = new StartPage(this);
    loginPage = new LoginPage(this);
    signUpPage = new SignUpPage(this);
    loginPage->hide();
    signUpPage->hide();
    startPage->move(150,150);
    QObject::connect(startPage, SIGNAL(showLoginPageSignal()),this, SLOT(showLoginPage()));
    QObject::connect(startPage, SIGNAL(showSignUpPageSignal()),this, SLOT(showSignUpPage()));
    QObject::connect(loginPage, SIGNAL(showStartPageSignal()),this, SLOT(showStartPage()));
    QObject::connect(signUpPage, SIGNAL(showStartPageSignal()),this, SLOT(showStartPage()));
    QObject::connect(loginPage, SIGNAL(showAppWindowSignal()),this, SLOT(showAppWindow()));

}

void StartWindow::showLoginPage(){
    loginPage->show();
}

void StartWindow::showSignUpPage(){
    signUpPage->show();
}

void StartWindow::showStartPage(){
    loginPage->hide();
    signUpPage->hide();
    startPage->show();
}

void StartWindow::showAppWindow(){
    hide();
    appWindow->show();
}
StartWindow::~StartWindow()
{
    delete ui;
}






