#include "Decimal.h"

void Decimal::changeExponent(int exponent) {
    if (this->exponent == exponent) {
    }
    else if (this->exponent < exponent) {
        for (int i = 0; i < exponent - this->exponent; i++) {
            this->mantissa *= 10;
        }
    }
    else {
        for (int i = 0; i < this->exponent - exponent; i++) {
            this->mantissa /= 10;
        }
    }
    this->exponent = exponent;
}


Decimal::Decimal () : mantissa(0), exponent(0) {
}

Decimal::Decimal (int mantissa, int exponent) :
       mantissa(mantissa), exponent(exponent) {
}

Decimal::Decimal (const Decimal& decimal) {
    this->mantissa = decimal.mantissa;
    this->exponent = decimal.exponent;
}

int Decimal::getMantissa() const {
    return this->mantissa;
}
int Decimal::getExponent() const {
    return this->exponent;
}

void Decimal::setMantissa(int mantissa) {
    this->mantissa = mantissa;
}
void Decimal::setExponent(int exponent) {
    this->exponent = exponent;
}


Decimal Decimal::operator+(const Decimal& b) {
    Decimal result(*this);
    Decimal tmp(b);
    result.exponent < tmp.exponent? result.changeExponent(tmp.exponent) :
                                    tmp.changeExponent(result.exponent);
    result.mantissa += tmp.mantissa;
    return result;
}

Decimal Decimal::operator-(const Decimal& b) {
    Decimal result(*this);
    Decimal tmp(b);
    result.exponent < tmp.exponent? result.changeExponent(tmp.exponent) :
                                    tmp.changeExponent(result.exponent);
    result.mantissa -= tmp.mantissa;
    return result;
}

Decimal Decimal::operator*(const Decimal& b) {
    Decimal result(*this);
    Decimal tmp(b);
    result.exponent < tmp.exponent? result.changeExponent(tmp.exponent) :
                                    tmp.changeExponent(result.exponent);
    result.mantissa *= tmp.mantissa;
    result.exponent += tmp.exponent;
    return result;
}

Decimal Decimal::operator/(const Decimal& b) {
    Decimal result(*this);
    Decimal tmp(b);
    result.exponent < tmp.exponent? result.changeExponent(tmp.exponent) :
                                    tmp.changeExponent(result.exponent);
    result.mantissa /= tmp.mantissa;
    result.exponent -= tmp.exponent;
    return result;
}

Decimal Decimal::operator*(int b) {
    Decimal result(*this);
    while (b%10 == 0) {
        result.exponent -= 1;
        b /= 10;
    }
    result.mantissa *= b;
    return result;
}

Decimal Decimal::operator/(int b) {
    Decimal result(*this);
    while (b%10 == 0) {
        result.exponent += 1;
        b /= 10;
    }
    result.mantissa /= b;
    return result;
}

ostream& operator<<(ostream &out, const Decimal &decimal) {
    int fractional = 0;
    int integral   = 0;
    int multiplier = 1;
    for (int i = 0; i < decimal.getExponent(); i++) {
        multiplier *= 10;
    }
    integral = decimal.getMantissa() / multiplier;
    out << integral;
    for (int i = 0; i > decimal.getExponent(); i--) {
        out << '0';
    }
    out << '.' << decimal.getMantissa() - integral * multiplier;
    return out;
}

istream& operator>>(istream &in, Decimal &decimal) {
    bool error              = false;
    char* input             = new char[120];
    int exponent            = 0;
    int mantissa            = 0;
    int currentCharNumber   = 0;
    in >> input;
    auto getNewMantissa = [&mantissa](char tmp) {
                                return mantissa * 10 + tmp - '0';
                            };
    for (char* tmp = input; *tmp != '\0'; tmp++) {
        if (*tmp >= '0' && *tmp <= '9') {
            mantissa = getNewMantissa(*tmp);
            exponent? exponent++: exponent;
        }
        else if (*tmp == '.' && exponent == 0) {
            exponent = 1;
            tmp++;
            if (*tmp >= '0' && *tmp <= '9') {
                mantissa = getNewMantissa(*tmp);
            }
            else if (*tmp == '\0') {
                mantissa *= 10;
            }
            else {
                error = true;
                break;
            }
        }
        else {
            error = true;
            break;
        }
    }
    delete[] input;
    if (error) {
        in.setstate(ios::failbit);
    }
    else {
        decimal.setMantissa(mantissa);
        decimal.setExponent(exponent);
    }
    return in;
}
