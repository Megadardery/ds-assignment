#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
    private:
        Fraction();
        Fraction(int n , int d);
        virtual ~Fraction();
        Fraction(const Fraction& other);
        Fraction operator=(const Fraction& other);
        Fraction operator+(const Fraction& other);
        Fraction operator-(const Fraction& other);
        Fraction operator*(const Fraction& other);
        Fraction operator/(const Fraction& other);
        bool operator<(const Fraction& other);
        bool operator>(const Fraction& other);
        bool operator==(const Fraction& other);
        bool operator>=(const Fraction& other);
        bool operator<=(const Fraction& other);
        friend std :: ostream& operator << (std :: ostream& out , const Fraction& f);
        friend std :: istream& operator >> (std :: istream& in , Fraction& f);

    private:
        int num;
        int denom;
        void reduce();
        friend class  FractionCalculator;
};

#endif // FRACTION_H
