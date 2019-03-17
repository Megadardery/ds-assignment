#ifndef BOOK_H
#define BOOK_H
#include <iostream>

class Book
{
    public:
        Book(std :: string a , std :: string n , int y);
        virtual ~Book();
        friend class BookStore;
        friend std :: ostream& operator << (std :: ostream& out, const Book* b);
    private:
        std :: string author;
        std :: string name;
        int year;
        int versions;
};

#endif // BOOK_H
