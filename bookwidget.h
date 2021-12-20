#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>

namespace Ui {
class BookWidget;
}

class BookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookWidget(QWidget *parent = nullptr, QString title = "", QString author = "", QString pages = "0", QString description = "", QString image = "/home/xenono/htdocs/library_db/women.jpg");
    ~BookWidget();

    const QString &getTitle() const;

    const QString &getAuthor() const;

    const QString &getDescription() const;

    const QString &getImage() const;

    const QString &getPages() const;

private:
    Ui::BookWidget *ui;
    QString Title;
    QString Author;
    QString Description;
    QString Image;
    QString Pages;
};

#endif // BOOKWIDGET_H
