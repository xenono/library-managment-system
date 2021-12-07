#ifndef USER_H
#define USER_H
#include <QApplication>
class User
{
public:
    User(QString username, QString email, QString userType);
    QString GetUsername();
    QString GetEmail();
    QString GetUserType();
private:
    QString Username;
    QString Email;
    QString UserType;
};

#endif // USER_H
