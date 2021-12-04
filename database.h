#ifndef DATABASE_H
#define DATABASE_H
#include <QApplication>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class Database
{
public:
    Database(QString databaseName, QString hostName, QString username, QString password);
    bool Connect();
    bool CheckCredentials(QString username, QString password);
    void CreateUser(QString username, QString email, QString password, QString ConfirmedPassword);
private:
    QSqlDatabase dbActor;
};

#endif // DATABASE_H
