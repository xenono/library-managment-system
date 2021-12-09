#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>
#include "profilepage.h"
#include "user.h"
#include "database.h"
#include "addbookpage.h"
#include <QtWidgets>

namespace Ui {
class AppWindow;
}

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr, Database *dbActor = nullptr);
    void SetLoggedUser(QString username);
    void HideAllViews();
    ~AppWindow();

private slots:
    void on_pushButton_2_clicked();
    void on_AddBook_clicked();

private:
    Ui::AppWindow *ui;
    User *LoggedUser;
    ProfilePage *profilePage;
    AddBookPage *addBookPage;
    Database *db;
    QPushButton* AddBookButton;
};

#endif // APPWINDOW_H
