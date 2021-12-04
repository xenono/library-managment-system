#include "signuppage.h"
#include "ui_signuppage.h"

SignUpPage::SignUpPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUpPage)
{
    ui->setupUi(this);
}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::on_pushButton_clicked()
{
    QString username = ui->lineEdit_4->text();
    QString email = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString confirmedPassword = ui->lineEdit_3->text();
    emit createAccountSignal(username,email,password,confirmedPassword);

}


void SignUpPage::on_pushButton_2_clicked()
{
    emit showStartPageSignal();
}



