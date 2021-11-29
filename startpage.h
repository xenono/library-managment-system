#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>

namespace Ui {
class StartPage;
}

class StartPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr);
    ~StartPage();

signals:
    void showLoginPageSignal();
    void showSignUpPageSignal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::StartPage *ui;
};

#endif // STARTPAGE_H
