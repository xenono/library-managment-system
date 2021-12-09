#include "appwindow.h"
#include "ui_appwindow.h"
#include "profilepage.h"
#include "addbookpage.h"

AppWindow::AppWindow(QWidget *parent, Database *dbActor) :
    QMainWindow(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->move(320,180);
    db = dbActor;
    profilePage = new ProfilePage(this);
    addBookPage = new AddBookPage(this);
    profilePage->move(0,150);
    addBookPage->move(0,150);
    profilePage->hide();
    addBookPage->hide();
    LoggedUser = nullptr;

//    AddBookButton = new QPushButton(this);
//    AddBookButton->hide();
//    AddBookButton->setText("Add book");
}

void AppWindow::SetLoggedUser(QString username){
    LoggedUser = db->GetUser(username);
    if(LoggedUser->GetUserType() != "librarian" && LoggedUser->GetUserType() != "admin"){
        ui->AddBook->hide();
    }
}

void AppWindow::HideAllViews(){
    profilePage->hide();
    addBookPage->hide();
}

AppWindow::~AppWindow()
{
    delete ui;
}

void AppWindow::on_pushButton_2_clicked()
{
    HideAllViews();
    profilePage->SetUserInfo(LoggedUser->GetUsername(),LoggedUser->GetEmail(),LoggedUser->GetUserType());
    profilePage->show();
}

void AppWindow::on_AddBook_clicked()
{
    HideAllViews();
    addBookPage->show();
}

