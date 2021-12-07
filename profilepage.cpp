#include "profilepage.h"
#include "ui_profilepage.h"

#include <QDir>

ProfilePage::ProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);

}

void ProfilePage::SetUserInfo(QString username, QString email, QString userType){


    ui->emailLabel->setText(email);
    ui->usernameLabel->setText(username);
    ui->userTypeLabel->setText(userType);
    QPixmap img("/home/xenono/htdocs/library_db/women.jpg");

    ui->image->setPixmap(img.scaled(400,450,Qt::KeepAspectRatio));
}
ProfilePage::~ProfilePage()
{
    delete ui;
}

//ui->usernameLabel->setText(username);
//ui->userTypeLabel->setText(userType);
//ui->emailLabel->setText(email);
