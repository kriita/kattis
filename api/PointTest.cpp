/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : PointTest.cpp
 */

#include "point.h"
#include "gtest/gtest.h"
#include <cmath>

TEST(PointTest, Constructor) {
  Point p(1, 2);
  EXPECT_EQ(1, p.x);
  EXPECT_EQ(2, p.y);
}

TEST(PointTest, Angle) {
  Point p(1, 1);
  EXPECT_EQ(M_PI_4, p.angle());
}

TEST(PointTest, AngleTo) {
  Point p1(1, 1);
  Point p2(2, 2);
  EXPECT_EQ(M_PI_4, p1.angleTo(p2));
}

TEST(PointTest, Add) {
  Point p1(1, 2);
  Point p2(3, 4);
  Point p3 = p1 + p2;
  EXPECT_EQ(4, p3.x);
  EXPECT_EQ(6, p3.y);
}

TEST(PointTest, Subtract) {
  Point p1(1, 2);
  Point p2(3, 4);
  Point p3 = p1 - p2;
  EXPECT_EQ(-2, p3.x);
  EXPECT_EQ(-2, p3.y);
}

TEST(PointTest, MultiplyWithScalar) {
  Point p(1, 2);
  Point p2 = p * 2;
  EXPECT_EQ(2, p2.x);
  EXPECT_EQ(4, p2.y);
}

TEST(PointTest, Length) {
  Point p(3, 4);
  EXPECT_EQ(5, p.length());
}

TEST(PointTest, DistanceTo) {
  Point p1(1, 2);
  Point p2(4, 6);
  EXPECT_EQ(5, p1.distanceTo(p2));
}

TEST(PointTest, DistanceToLine) {
  Point p1(0, 1);
  Point p2(2, 1);
  Point p3(1, 1);
  EXPECT_EQ(0, p3.distanceTo(p1, p2));
}

TEST(PointTest, Cross) {
  Point p1(1, 2);
  Point p2(3, 4);
  EXPECT_EQ(-2, p1.cross(p2));
}

TEST(PointTest, Dot) {
  Point p1(1, 2);
  Point p2(3, 4);
  EXPECT_EQ(11, p1.dot(p2));
}

TEST(PointTest, CCW) {
  Point p1(1, 2);
  Point p2(3, 4);
  Point p3(5, 6);
  EXPECT_EQ(0, p1.ccw(p2, p3));
}

TEST(PointTest, CCWNegative) {
  Point p1(1, 0);
  Point p2(0, 0);
  Point p3(0, 1);
  EXPECT_EQ(p1.ccw(p2, p3), -1);
}

TEST(PointTest, CCWPositive) {
  Point p1(0, 0);
  Point p2(1, 0);
  Point p3(0, 1);
  EXPECT_EQ(p1.ccw(p2, p3), 1);
}

TEST(PointTest, LessThan) {
  Point p1(1, 2);
  Point p2(3, 4);
  EXPECT_TRUE(p1 < p2);
}

TEST(PointTest, Equal) {
  Point p1(1, 2);
  Point p2(1, 2);
  EXPECT_TRUE(p1 == p2);
}

TEST(PointTest, NotEqual) {
  Point p1(1, 2);
  Point p2(3, 4);
  EXPECT_TRUE(p1 != p2);
}

TEST(PointTest, OperatorInput) {
  Point p1(1, 2);
  std::stringstream ss;
  ss << p1;
  Point p2;
  ss >> p2;
  EXPECT_EQ(p1, p2);
}

TEST(PointTest, OperatorOutput) {
  Point p1(1, 2);
  std::stringstream ss;
  ss << p1;
  EXPECT_EQ("1 2", ss.str());
}
