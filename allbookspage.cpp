#include "allbookspage.h"
#include "ui_allbookspage.h"
#include <Qt>
#include <QScrollArea>

AllBooksPage::AllBooksPage(QWidget *parent, Database* dbActor) :
    QWidget(parent),
    ui(new Ui::AllBooksPage)
{
    ui->setupUi(this);
    VerticalBooksLayout = new QVBoxLayout;
    // Get all books from database
    db = dbActor;
    QSqlQuery AllBooksQuery = db->GetAllBooks();
    // Process SQL query and add all books into a list
    FillBooksList(AllBooksQuery);

    // Setup scroll area
    ui->scrollAreaWidgetContents->setLayout(VerticalBooksLayout);
    ui->scrollAreaWidgetContents->setMinimumHeight(ListOfBooks.size() * 400);
//    ui->scrollArea->setWidget(
//    for(BookWidget* book:ListOfBooks){
//        book->setGeometry(QRect(110, 80, 120, 80));
//        ui->scrollAreaWidgetContents->layout()->addWidget(book);
//    }
//    ui->scrollArea->setWidget(central);
//    ui->scrollArea->setWidgetResizable(true);
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
        temp = new BookWidget(nullptr,title,author,pages,description,image);
        VerticalBooksLayout->addWidget(temp);
        ListOfBooks.push_back(temp);
    }
}

AllBooksPage::~AllBooksPage()
{
    delete ui;
}
