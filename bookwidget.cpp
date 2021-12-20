#include "bookwidget.h"
#include "ui_bookwidget.h"

BookWidget::BookWidget(QWidget *parent, QString title, QString author, QString pages, QString description, QString image) :
    QWidget(parent),
    ui(new Ui::BookWidget)
{
    ui->setupUi(this);
    Title = title;
    Author = author;
    Pages = pages;
    Description = description;
    Image = image;
    ui->AuthorField->setText(Author);
    ui->PagesField->setText(Pages);
    ui->TitleField->setText(Title);
    QPixmap img(Image);

    ui->ImageField->setPixmap(img.scaled(400,450,Qt::KeepAspectRatio));
}

BookWidget::~BookWidget()
{
    delete ui;
}

const QString &BookWidget::getTitle() const
{
    return Title;
}

const QString &BookWidget::getAuthor() const
{
    return Author;
}

const QString &BookWidget::getDescription() const
{
    return Description;
}

const QString &BookWidget::getImage() const
{
    return Image;
}

const QString &BookWidget::getPages() const
{
    return Pages;
}
