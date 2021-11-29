#include "appwindow.h"
#include "ui_appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    this->move(420,0);
}

AppWindow::~AppWindow()
{
    delete ui;
}
