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
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::SignUpPage *ui;
};

#endif // SIGNUPPAGE_H
