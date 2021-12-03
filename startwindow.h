#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "startpage.h"
#include "signuppage.h"
#include "loginpage.h"
#include "appwindow.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr, AppWindow *appWindowPointer = nullptr, Database *dbActor=nullptr);
    ~StartWindow();


public slots:
    void showLoginPage();
    void showSignUpPage();
    void showStartPage();
    void showAppWindow();


private slots:


private:
    Ui::StartWindow *ui;
    StartPage *startPage;
    LoginPage *loginPage;
    SignUpPage *signUpPage;
    AppWindow *appWindow;
    Database *db;
};
#endif // STARTWINDOW_H
