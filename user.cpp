#include "user.h"
#include "database.h"
User::User(QString username,QString email,QString userType)
{    Username = username;
     Email = email;
     UserType = userType;
}

QString User::GetUsername(){
    return this->Username;
}
QString User::GetEmail(){
    return this->Email;
}
QString User::GetUserType(){
    return this->UserType;
}
