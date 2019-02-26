#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <string>
#include <iostream>
class StudentName
{
    public:
        StudentName(std :: string n);
        virtual ~StudentName();

        void print();
        bool replace(int i , int j);

    private:
        static const int siz = 3;
        std::string name[siz];
};
/*
    StudentName b("belal") , n("Ahmed Nasr") , d("Ahemd Nasr Eldardery"),h(" belal Hamdy");
    b.print();
    n.print();
    d.print();
    h.print();
    if (d.replace(0,2)) d.print();
*/
///for testing
#endif // STUDENTNAME_H
