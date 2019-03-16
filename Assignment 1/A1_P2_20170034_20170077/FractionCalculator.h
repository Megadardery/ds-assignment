#include "Fraction.h"
#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H

class FractionCalculator
{
    public:
        FractionCalculator();
        virtual ~FractionCalculator();
        bool operation();
        Fraction getResult();
    private:
        Fraction result,f1,f2;
        int getNumber(int begin, int end, std :: string message);
        void getFractions();
};

#endif // FRACTIONCALCULATOR_H
