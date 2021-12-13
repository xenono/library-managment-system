#include "addbookpage.h"
#include "ui_addbookpage.h"

#include <QFileDialog>
#include <QDir>

#define SERVER "/home/xenono/htdocs/library_db/"

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
    QString Title = ui->Title->text();
    QString Author = ui->Author->text();
    QString Description = ui->Description->toPlainText();
    int Pages = ui->Pages->text().toInt();

    QString file_name = QFileDialog::getOpenFileName(this, "Choose a file", QDir::homePath()); // Last arugment filter, later add .jpg,.png.jpeg
    QString ImageExtension = "." + file_name.split(".")[file_name.split(".").length() - 1];
    QString Image = SERVER + Title + ImageExtension;
    QFile::remove(Image);
    QFile::copy(file_name,Image);
    emit CreateBookSignal(Title, Author,Pages,Image,Description);
}

