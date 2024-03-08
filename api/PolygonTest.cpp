#include <gtest/gtest.h>
#include "polygon.h"
#include "point.h"
#include "edge.h"

#include <vector>

TEST(PolygonTest, Constructor) {
  std::vector<Point> points = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
  Polygon p1(points);
  EXPECT_EQ(p1.points, points);
}

TEST(PolygonTest, Area) {
  std::vector<Point> points = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
  Polygon p1(points);
  EXPECT_EQ(p1.area(), 1);
}

TEST(PolygonTest, Contains) {
  std::vector<Point> points = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
  Polygon p1(points);
  Point p2(0.5, 0.5);
  EXPECT_EQ(p1.contains(p2), 1);
}

TEST(PolygonTest, On) {
  std::vector<Point> points = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
  Polygon p1(points);
  Point p2(0, 0.5);
  EXPECT_TRUE(p1.on(p2));
}
