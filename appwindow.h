#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "profilepage.h"

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr);
    void SetLoggedUser(QString username, QString password, QString UserType = "librarian");
    ~AppWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::AppWindow *ui;
    QString Username;
    QString Password;
    QString Email;
    QString UserType;
    ProfilePage *profilePage;
};

#endif // APPWINDOW_H
