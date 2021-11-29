#include "startwindow.h"
#include "appwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppWindow *appWindow = new AppWindow();
    StartWindow *startWindow = new StartWindow(nullptr, appWindow);

    startWindow->show();
    return a.exec();
}
