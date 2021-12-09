#include "addbookpage.h"
#include "ui_addbookpage.h"

#include <QFileDialog>
#include <QDir>

AddBookPage::AddBookPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBookPage)
{
    ui->setupUi(this);
}

AddBookPage::~AddBookPage()
{
    delete ui;
}

void AddBookPage::on_UploadImageButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Choose a file", QDir::homePath()); // Last arugment filter, later add .jpg,.png.jpeg
    qDebug() << file_name;
    QFile::remove("/home/xenono/htdocs/library_db/dog.jpg");
    QFile::copy(file_name,"/home/xenono/htdocs/library_db/dog.jpg");
}

