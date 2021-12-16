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
    Image["FileName"] = QFileDialog::getOpenFileName(this, "Choose a file", QDir::homePath()); // Last arugment filter, later add .jpg,.png.jpeg

    Image["ImageExtension"] = "." + Image["FileName"].split(".")[Image["FileName"].split(".").length() - 1];
    Image["Destination"] = SERVER + Title + Image["ImageExtension"];
}


void AddBookPage::on_pushButton_clicked()
{
    QString Title = ui->Title->text();
    QString Author = ui->Author->text();
    QString Description = ui->Description->toPlainText();
    int Pages = ui->Pages->text().toInt();
    QFile::remove(Image["Destination"]);
    QFile::copy(Image["FileName"],Image["Destination"]);
    emit CreateBookSignal(Title, Author,Pages,Image["Destination"],Description);

}

