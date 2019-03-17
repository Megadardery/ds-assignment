#include "Book.h"
#include <iostream>
Book::Book(std :: string a, std :: string n , int y)
{
    versions = 1;
    author = a;
    name = n;
}

Book::~Book()
{

}
std :: ostream& operator << (std :: ostream& out, const Book* b)
{
    out <<"Name : " << b->name <<"\nAuthor : " << b->author << "\nYear : " << b->year << "\nVersions : " << b->versions << "\n-----------------------------\n";
    return out;
}
