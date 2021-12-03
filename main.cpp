#include "startwindow.h"
#include "appwindow.h"
#include "database.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database *db = new Database("library_db", "127.0.0.1","root","");
    if(!db->Connect()){
        return 0;
    }

    AppWindow *appWindow = new AppWindow();
    StartWindow *startWindow = new StartWindow(nullptr, appWindow, db);

    startWindow->show();
    return a.exec();
}
