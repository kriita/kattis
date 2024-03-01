#include "rationalnumber.hpp"
#include <gtest/gtest.h>

TEST(RationalNumberTest, GreaterThanTrue) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);

    ASSERT_TRUE(a > b);
}

TEST(RationalNumberTest, GreaterThanFalse) {
    RationalNumber a(1, 3);
    RationalNumber b(1, 2);

    ASSERT_FALSE(a > b);
}

TEST(RationalNumberTest, LessThanTrue) {
    RationalNumber a(1, 3);
    RationalNumber b(1, 2);

    ASSERT_TRUE(a < b);
}

TEST(RationalNumberTest, LessThanFalse) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);

    ASSERT_FALSE(a < b);
}

TEST(RationalNumberTest, GreaterThanOrEqualTrue) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 2);

    ASSERT_TRUE(a >= b);
}

TEST(RationalNumberTest, GreaterThanOrEqualFalse) {
    RationalNumber a(1, 3);
    RationalNumber b(1, 2);

    ASSERT_FALSE(a >= b);
}

TEST(RationalNumberTest, LessThanOrEqualTrue) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 2);

    ASSERT_TRUE(a <= b);
}

TEST(RationalNumberTest, LessThanOrEqualFalse) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);

    ASSERT_FALSE(a <= b);
}

TEST(RationalNumberTest, EqualTrue) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 2);

    ASSERT_TRUE(a == b);
}

TEST(RationalNumberTest, EqualFalse) {
    RationalNumber a(1, 3);
    RationalNumber b(1, 2);

    ASSERT_FALSE(a == b);
}

TEST(RationalNumberTest, NotEqualTrue) {
    RationalNumber a(1, 3);
    RationalNumber b(1, 2);

    ASSERT_TRUE(a != b);
}

TEST(RationalNumberTest, NotEqualFalse) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 2);

    ASSERT_FALSE(a != b);
}

TEST(RationalNumberTest, Add) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);
    RationalNumber c = a + b;

    ASSERT_EQ(c, RationalNumber(5, 6));
}

TEST(RationalNumberTest, Subtract) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);
    RationalNumber c = a - b;

    ASSERT_EQ(c, RationalNumber(1, 6));
}

TEST(RationalNumberTest, Multiply) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);
    RationalNumber c = a * b;

    ASSERT_EQ(c, RationalNumber(1, 6));
}

TEST(RationalNumberTest, Divide) {
    RationalNumber a(1, 2);
    RationalNumber b(1, 3);
    RationalNumber c = a / b;

    ASSERT_EQ(c, RationalNumber(3, 2));
}
