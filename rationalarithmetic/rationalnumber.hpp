/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : rationalnumber.hpp
 */

#include <iostream>

class RationalNumber {
public:
    RationalNumber();
    RationalNumber(long long numerator, long long denominator);

    RationalNumber operator+(const RationalNumber& other) const;
    RationalNumber operator-(const RationalNumber& other) const;
    RationalNumber operator*(const RationalNumber& other) const;
    RationalNumber operator/(const RationalNumber& other) const;

    bool operator>(const RationalNumber& other) const;
    bool operator<(const RationalNumber& other) const;
    bool operator>=(const RationalNumber& other) const;
    bool operator<=(const RationalNumber& other) const;
    bool operator==(const RationalNumber& other) const;
    bool operator!=(const RationalNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const RationalNumber& rn);
    friend std::istream& operator>>(std::istream& is, RationalNumber& rn);

    void simplify();
private:
    long long numerator;
    long long denominator;
    long long gcd(long long a, long long b) const;
};
