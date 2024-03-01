/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : rationalnumber.cpp
 */

#include "rationalnumber.hpp"

#include <iostream>

RationalNumber::RationalNumber() {
    numerator = 0;
    denominator = 1;
}

RationalNumber::RationalNumber(long long numerator, long long denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    simplify(); // Always simplify on creation
}

RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
    long long newNumerator = numerator * other.denominator + other.numerator * denominator;
    long long newDenominator = denominator * other.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
    long long newNumerator = numerator * other.denominator - other.numerator * denominator;
    long long newDenominator = denominator * other.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
    long long newNumerator = numerator * other.numerator;
    long long newDenominator = denominator * other.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
    long long newNumerator = numerator * other.denominator;
    long long newDenominator = denominator * other.numerator;
    return RationalNumber(newNumerator, newDenominator);
}

bool RationalNumber::operator>(const RationalNumber& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool RationalNumber::operator<(const RationalNumber& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool RationalNumber::operator>=(const RationalNumber& other) const {
    return numerator * other.denominator >= other.numerator * denominator;
}

bool RationalNumber::operator<=(const RationalNumber& other) const {
    return numerator * other.denominator <= other.numerator * denominator;
}

bool RationalNumber::operator==(const RationalNumber& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool RationalNumber::operator!=(const RationalNumber& other) const {
    return numerator * other.denominator != other.numerator * denominator;
}

void RationalNumber::simplify() {
    long long divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
}

long long RationalNumber::gcd(long long a, long long b) const {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& rn) {
    os << rn.numerator << " / " << rn.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, RationalNumber& rn) {
    is >> rn.numerator >> rn.denominator;
    rn.simplify();
    return is;
}
