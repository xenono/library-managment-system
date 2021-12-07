#ifndef ALLBOOKSPAGE_H
#define ALLBOOKSPAGE_H

#include <QWidget>

namespace Ui {
class AllBooksPage;
}

class AllBooksPage : public QWidget
{
    Q_OBJECT

public:
    explicit AllBooksPage(QWidget *parent = nullptr);
    ~AllBooksPage();

private:
    Ui::AllBooksPage *ui;
};

#endif // ALLBOOKSPAGE_H
