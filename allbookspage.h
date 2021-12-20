#ifndef ALLBOOKSPAGE_H
#define ALLBOOKSPAGE_H

#include <QWidget>
#include "database.h"
#include <QVector>

namespace Ui {
class AllBooksPage;
}

class AllBooksPage : public QWidget
{
    Q_OBJECT


public:
    explicit AllBooksPage(QWidget *parent = nullptr, Database* dbActor = nullptr);
    void FillBooksList(QSqlQuery query);
    ~AllBooksPage();

private:
    Ui::AllBooksPage *ui;
    Database* db;
    QVector<BookWidget*> ListOfBooks;


};

#endif // ALLBOOKSPAGE_H
