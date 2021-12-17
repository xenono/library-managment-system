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
    explicit BookWidget(QWidget *parent = nullptr, QString title = "", QString author = "", QString pages = "0", QString description = "", QString image = "");
    ~BookWidget();

private:
    Ui::BookWidget *ui;
    QString Title;
    QString Author;
    QString Description;
    QString Image;
    QString Pages;
};

#endif // BOOKWIDGET_H
