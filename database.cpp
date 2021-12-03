#include "database.h"
#include<QMessageBox>
Database::Database(QString databaseName, QString hostName, QString username, QString password)
{
    dbActor = QSqlDatabase::addDatabase("QMYSQL");
    dbActor.setHostName(hostName);
    dbActor.setDatabaseName(databaseName);
    dbActor.setUserName(username);
    dbActor.setPassword(password);
}


bool Database::Connect(){
    bool isConnected = dbActor.open();
    if(isConnected)
        qInfo("Database connected");
    else{
        QMessageBox errorBox;
        errorBox.setText("Failed to connect to the database!");
        errorBox.exec();
    }
    return isConnected;

}

bool Database::CheckCredentials(QString username, QString password){
    QSqlQuery query("SELECT username,password FROM users WHERE username='" +username + "' AND password='" + password + "'");
    query.exec();
    if(query.next())
        return 1;
    else
        return 0;
    return 1;
}
