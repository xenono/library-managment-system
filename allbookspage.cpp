#include "allbookspage.h"
#include "ui_allbookspage.h"

AllBooksPage::AllBooksPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllBooksPage)
{
    ui->setupUi(this);
}

AllBooksPage::~AllBooksPage()
{
    delete ui;
}
