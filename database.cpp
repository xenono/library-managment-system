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
    if(!isConnected){
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

void Database::CreateUser(QString username, QString email, QString password, QString confirmedPassword){
   if(password != confirmedPassword){
       QMessageBox errorBox;
       errorBox.setText("Passwords are not the same!");
       errorBox.exec();
       return;
   }
   QSqlQuery query;
   query.prepare("INSERT INTO users (username,email,password) VALUES (:username,:email,:password)");
   query.bindValue(":username", username);
   query.bindValue(":email", email);
   query.bindValue(":password", password);
   query.exec();
}

User Database::GetUser(QString username){
    QSqlQuery query;
    QString Email, UserType;
    query.prepare("SELECT * from users WHERE username=:username");
    query.bindValue(":username", username);
    query.exec();
    if(query.next()){
        Email = query.value("email").toString();
        UserType = query.value("user_type").toString();
    }
}







