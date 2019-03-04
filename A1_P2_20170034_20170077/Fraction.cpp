#include "Fraction.h"
#include <algorithm>

Fraction::Fraction()
{
    num = 1 ;
    denom = 1;
}
Fraction::Fraction(int n, int d)
{
    num = n ;
    denom = d;
    reduce();
}

Fraction::~Fraction()
{

}

Fraction::Fraction(const Fraction& other)
{
    denom = other.denom;
    num = other.num;
}

Fraction Fraction::operator=(const Fraction& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    denom = rhs.denom;
    num = rhs.num;
    return *this;
}

Fraction Fraction:: operator+(const Fraction& other)
{
    return Fraction(num*other.denom + denom* other.num,denom*other.denom);
}
Fraction Fraction:: operator-(const Fraction& other)
{
    return Fraction(num*other.denom - denom* other.num,denom*other.denom);
}
Fraction Fraction:: operator*(const Fraction& other)
{
    return Fraction (num*other.num, denom * other.denom);
}
Fraction Fraction:: operator/(const Fraction& other)
{
    return *this * Fraction(other.denom,other.num);
}
bool Fraction:: operator<(const Fraction& other)
{
    return ((1.0 * num / denom) < (1.0 * other.num / other.denom ) && ! (*this == other));
}
bool Fraction:: operator>(const Fraction& other)
{
    return (!(*this<=other));
}
bool Fraction:: operator==(const Fraction& other)
{
    return (num == other.num && denom == other.denom);
}
bool Fraction:: operator>=(const Fraction& other)
{
    return (*this > other || *this == other);
}
bool Fraction:: operator<=(const Fraction& other)
{
    return (*this < other || *this == other);
}
//return b? a : gcd(b , a%b)
void Fraction:: reduce()
{
    if (!num) denom = 1;
    else if (!denom) num = 1;
    else
    {
        int n1 = abs(num), n2 = abs(denom);
         while(n1 != n2)
        {
            if(n1 > n2)
                n1 -= n2;
            else
                n2 -= n1;
        }
        num/=n1;
        denom/=n2;
    }
}
std :: ostream& operator << (std :: ostream& out ,const Fraction& f)
{
    if (f.num == 0) out << f.num;
    else if (f.denom == 1) out << f.num;
    else out << f.num<<"/" <<f.denom;
    return out;
}
std :: istream& operator >> (std :: istream& in , Fraction& f)
{
    char delm;
    in >> f.num >> delm >> f.denom;
    return in;
}
