#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>

namespace Ui {
class SignUpPage;
}

class SignUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

signals:
    void showStartPageSignal();
    void createAccountSignal(QString username, QString email, QString password, QString confirmedPassword);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::SignUpPage *ui;
};

#endif // SIGNUPPAGE_H
