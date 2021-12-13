#ifndef ADDBOOKPAGE_H
#define ADDBOOKPAGE_H

#include <QWidget>

namespace Ui {
class AddBookPage;
}

class AddBookPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddBookPage(QWidget *parent = nullptr);
    ~AddBookPage();



private slots:
    void on_UploadImageButton_clicked();

signals:
    void CreateBookSignal(QString title, QString author, int pages, QString image, QString description);

private:
    Ui::AddBookPage *ui;
};

#endif // ADDBOOKPAGE_H
