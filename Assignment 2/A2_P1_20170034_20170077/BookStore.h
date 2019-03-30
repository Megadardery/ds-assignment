#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include <algorithm>
#include <vector>
#include "Book.h"
class BookStore
{
    public:
        BookStore();
        virtual ~BookStore();
        void PrintMenu (std :: ostream& out , std :: istream& in);
    private:
        void AddBook(const Book& b);
        void ListBooks (std :: ostream& out);
        Book* SearchbyName(std :: string n);
        Book* SearchbyAuthor(std :: string a);
        Book* FindHighest ();
        void Update (Book* upd , int v);
        std :: vector <Book> data;
};

#endif // BOOKSTORE_H
