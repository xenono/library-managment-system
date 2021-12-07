#include "startwindow.h"
#include "startpage.h"
#include "loginpage.h"
#include "signuppage.h"
#include "ui_startwindow.h"
#include "appwindow.h"
#include "database.h"

#include <QMessageBox>

StartWindow::StartWindow(QWidget *parent, AppWindow *appWindowPointer, Database *dbActor)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    this->move(560,240);
    appWindow = appWindowPointer;
    db = dbActor;
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
    QObject::connect(loginPage, SIGNAL(LoginSignal(QString,QString)),this, SLOT(Login(QString,QString)));
    QObject::connect(signUpPage, SIGNAL(createAccountSignal(QString,QString,QString,QString)),this, SLOT(CreateAccount(QString,QString,QString,QString)));


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

void StartWindow::Login(QString username, QString password){
    if(db->CheckCredentials(username,password)){
        hide();
        appWindow->SetLoggedUser(username);
        appWindow->show();
        return;
    }
    QMessageBox errorBox;
    errorBox.setText("Invalid Credentials!");
    errorBox.exec();

}

void StartWindow::CreateAccount(QString username, QString email, QString password, QString confirmedPassword){
   db->CreateUser(username,email,password,confirmedPassword);
}

StartWindow::~StartWindow()
{
    delete ui;
}






