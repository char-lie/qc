#pragma once
#include <iostream>

using namespace std;

/*
 * Represents numbers in view `n = mantissa * 10^(-exponent)'.
 * Because it's not good to use standard floating point types
 * for representing money amount.
 */
class Decimal {

    private:
        int mantissa;
        int exponent;

        void changeExponent(int exponent);

    public:

        Decimal ();
        Decimal (int mantissa, int exponent = 0);
        Decimal (const Decimal& decimal);

        int getMantissa() const;
        int getExponent() const;

        void setMantissa(int mantissa);
        void setExponent(int exponent);

        Decimal operator+(const Decimal& b);
        Decimal operator-(const Decimal& b);
        Decimal operator*(int b);
        Decimal operator/(int b);
        Decimal operator*(const Decimal& b);
        Decimal operator/(const Decimal& b);
};

ostream& operator<<(ostream &out, const Decimal &decimal);
istream& operator>>(istream &in,  Decimal &decimal);
