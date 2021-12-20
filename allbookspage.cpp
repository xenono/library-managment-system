#include "allbookspage.h"
#include "ui_allbookspage.h"

AllBooksPage::AllBooksPage(QWidget *parent, Database* dbActor) :
    QWidget(parent),
    ui(new Ui::AllBooksPage)
{
    ui->setupUi(this);
    db = dbActor;
    QSqlQuery AllBooksQuery = db->GetAllBooks();
    FillBooksList(AllBooksQuery);
        for(BookWidget* book:ListOfBooks){
            ui->verticalLayout->addWidget(book);
        }
}

void AllBooksPage::FillBooksList(QSqlQuery query){
    BookWidget *temp;
    QString title,author,pages,description,image;
    while(query.next()){
        title = query.value("title").toString();
        author = query.value("author").toString();
        pages = query.value("pages").toString();
        description = query.value("description").toString();
        image = query.value("image").toString();
        temp = new BookWidget(this,title,author,pages,description,image);

        ListOfBooks.push_back(temp);
    }
}

AllBooksPage::~AllBooksPage()
{
    delete ui;
}
