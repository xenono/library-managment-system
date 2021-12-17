#include "appwindow.h"
#include "ui_appwindow.h"
#include "profilepage.h"
#include "addbookpage.h"
#include "allbookspage.h"

AppWindow::AppWindow(QWidget *parent, Database *dbActor) :
    QMainWindow(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->move(320,180);
    db = dbActor;
    profilePage = new ProfilePage(this);
    addBookPage = new AddBookPage(this);
    allBooksPage = new AllBooksPage(this);
    allBooksPage->move(0,150);
    profilePage->move(0,150);
    addBookPage->move(0,150);
    profilePage->hide();
    addBookPage->hide();
    LoggedUser = nullptr;

//    AddBookButton = new QPushButton(this);
//    AddBookButton->hide();
//    AddBookButton->setText("Add book");
    QObject::connect(addBookPage, SIGNAL(CreateBookSignal(QString,QString,int,QString,QString)), this,SLOT(CreateBook(QString,QString,int,QString,QString)));
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
    allBooksPage->hide();
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
void AppWindow::CreateBook(QString title, QString author, int pages, QString image, QString description){
    db->CreateBook(title,author,pages,image,description);
}


void AppWindow::on_pushButton_clicked()
{
    HideAllViews();
    allBooksPage->show();
}

