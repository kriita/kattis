/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : {{FILE}}
 */

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "edge.h"
#include "point.h"

TEST(EdgeTest, Constructor) {
  Point p1(0, 0);
  Point p2(1, 1);
  Edge e1(p1, p2);
  EXPECT_EQ(e1.u, p1);
  EXPECT_EQ(e1.v, p2);
  EXPECT_EQ(e1.weight, 0);
}

TEST(EdgeTest, Intersect) {
  Point p1(0, 0);
  Point p2(1, 1);
  Point p3(1, 0);
  Point p4(0, 1);
  Edge e1(p1, p2);
  Edge e2(p3, p4);
  EXPECT_TRUE(e1.intersect(e2));
}

TEST(EdgeTest, NoIntersect) {
  Point p1(0, 1);
  Point p2(1, 1);
  Point p3(0, 0);
  Point p4(1, 0);
  Edge e1(p1, p2);
  Edge e2(p3, p4);
  EXPECT_FALSE(e1.intersect(e2));
}

TEST(EdgeTest, Contains) {
  Point p1(0, 0);
  Point p2(1, 1);
  Point p3(0.5, 0.5);
  Edge e1(p1, p2);
  EXPECT_TRUE(e1.contains(p3));
}

TEST(EdgeTest, Length) {
  Point p1(0, 0);
  Point p2(1, 1);
  Edge e1(p1, p2);
  EXPECT_EQ(e1.length(), sqrt(2));
}

TEST(EdgeTest, Intersection) {
  Point p1(0, 0);
  Point p2(1, 1);
  Point p3(0, 1);
  Point p4(1, 0);
  Edge e1(p1, p2);
  Edge e2(p3, p4);
  std::vector<Point> v = e1.intersection(e2);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], Point(0.5, 0.5));
}

TEST(EdgeTest, IntersectionSegment) {
  Point p1(0, -1);
  Point p2(0, 1);
  Point p3(0, 0);
  Point p4(0, 2);
  Edge e1(p1, p2);
  Edge e2(p3, p4);
  std::vector<Point> v = e1.intersection(e2);
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v[0], Point(0, 0));
  EXPECT_EQ(v[1], Point(0, 1));
}

TEST(EdgeTest, OperatorLess) {
  Point p1(0, 0);
  Point p2(1, 1);
  Point p3(1, 2);
  Point p4(0, 1);
  Edge e1(p1, p2, 0);
  Edge e2(p3, p4, 1);
  EXPECT_TRUE(e1 < e2);
}

TEST(EdgeTest, OperatorEqual) {
  Point p1(0, 0);
  Point p2(1, 1);
  Edge e1(p1, p2);
  Edge e2(p1, p2);
  EXPECT_TRUE(e1 == e2);
}

TEST(EdgeTest, OperatorInput) {
  Point p1(0, 0);
  Point p2(1, 1);
  Edge e1(p1, p2);
  std::istringstream iss("0 0 1 1");
  iss >> e1;
  EXPECT_EQ(e1.u, p1);
  EXPECT_EQ(e1.v, p2);
}
