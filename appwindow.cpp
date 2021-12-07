#include "appwindow.h"
#include "ui_appwindow.h"
#include "profilepage.h"

AppWindow::AppWindow(QWidget *parent, Database *dbActor) :
    QMainWindow(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->move(320,180);
    db = dbActor;
    profilePage = new ProfilePage(this);
    profilePage->move(0,150);
    profilePage->hide();
    LoggedUser = nullptr;
    AddBookButton = new QPushButton(this);
    AddBookButton->hide();
    AddBookButton->setText("Add book");
}

void AppWindow::SetLoggedUser(QString username){
    LoggedUser = db->GetUser(username);
    if(LoggedUser->GetUserType() == "librarian" || LoggedUser->GetUserType() == "admin"){
        AddBookButton->show();
        ui->gridLayout->addWidget(AddBookButton);
    }
}
AppWindow::~AppWindow()
{
    delete ui;
}

void AppWindow::on_pushButton_2_clicked()
{
    profilePage->SetUserInfo(LoggedUser->GetUsername(),LoggedUser->GetEmail(),LoggedUser->GetUserType());
    profilePage->show();
}

