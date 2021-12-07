#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>

namespace Ui {
class ProfilePage;
}

class ProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit ProfilePage(QWidget *parent = nullptr);
    void SetUserInfo(QString username, QString email, QString userType);
    ~ProfilePage();

private:
    Ui::ProfilePage *ui;
};

#endif // PROFILEPAGE_H
