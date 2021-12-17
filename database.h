#ifndef DATABASE_H
#define DATABASE_H
#include <QApplication>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "user.h"
#include "bookwidget.h"
#include <list>

using std::list;

class Database
{
public:
    Database(QString databaseName, QString hostName, QString username, QString password);
    bool Connect();
    bool CheckCredentials(QString username, QString password);
    void CreateUser(QString username, QString email, QString password, QString ConfirmedPassword);
    void CreateBook(QString title, QString author, int pages, QString image, QString description);
    User *GetUser(QString username);
    QSqlQuery* GetAllBooks();

private:
    QSqlDatabase dbActor;
};

#endif // DATABASE_H
