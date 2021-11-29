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

void SignUpPage::on_pushButton_2_clicked()
{
    emit showStartPageSignal();
}

