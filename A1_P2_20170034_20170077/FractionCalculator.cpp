#include "FractionCalculator.h"

FractionCalculator::FractionCalculator()
{
}

FractionCalculator::~FractionCalculator()
{
}
Fraction FractionCalculator:: getResult()
{
    return result;
}
int FractionCalculator:: getNumber(int begin, int end, std :: string message)
{
    int answer;
    while (true)
    {
        std :: cout << message;
        std :: cin >> answer;
        if (std :: cin.fail())
        {
            std :: cin.clear();
            std :: cin.ignore(INT_MAX, '\n');
            std :: cout << "Invalid input.\n";
        }
        else if (answer < begin || answer > end)
        {
            std :: cout << "Input out of range (" << begin << "-" << end << ")\n";
        }
        else
        {
           std :: cin.ignore(INT_MAX, '\n');
            break;
        }
    }
    return answer;
}
void FractionCalculator :: getFractions ()
{
    std :: string msg;
    msg = "First Fraction : To input Fraction (1) to use the result (2) : ";
    int c = getNumber(1,2,msg);
    if (c == 2) f1 = result;
    else std :: cin >> f1;
    msg = "Second Fraction : To input Fraction (1) to use the result (2) : ";
    c = getNumber(1,2,msg);
    if (c == 2) f2 = result;
    else std :: cin >> f2;
}
bool FractionCalculator :: operation()
{
    std :: string msg;
    std :: string menu = "1- Add Fractions\n2- Subtract Fractions\n3- Multiply Fractions\n4- Divide Fractions\n5- Print previous result\n6- Print first fraction\n7- Print second Fraction\n0- Exit\n";
    while (true)
    {

        int answer = getNumber(0,7,menu);
        switch(answer)
        {
        case 0:
            return answer;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            getFractions();
        }
        std :: cout << "\n= " ;
        switch(answer)
        {
        case 1:
            result = f1 + f2;
            std :: cout << result;
            break;
        case 2:
            result = f1 - f2;
            std :: cout << result;
            break;
        case 3:
            result = f1 * f2;
            std :: cout << result;
            break;
        case 4:
            result = f1 / f2;
            std :: cout << result;
            break;
        case 5:
            std :: cout << result;
            break;
        case 6:
            std :: cout << f1;
            break;
        case 7:
            std :: cout << f2;
            break;

        }
        std :: cout << "\n\n";
    }
}
