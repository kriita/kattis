/*
 * Simple point class
 */
#include<cmath>
#include<tuple>
#include "point.h"

Point::Point(double _x, double _y) :
  x(_x), y(_y)
{}

double Point::distanceTo(Point p)
{
  double dx = x - p.x;
  double dy = y - p.y;
  return sqrt(dx*dx + dy*dy);
}

bool Point::operator<(const Point& p) const
{
  return std::tie(x, y) < std::tie(p.x, p.y);
}

bool Point::operator==(const Point& p) const
{
  return !(*this < p || p < *this);
}

bool Point::operator!=(const Point& p) const
{
  return *this < p || p < *this;
}

// ccw checks if the sequence of points is counter-clockwise
// If clockwise:          1
// If counter-clockwise: -1
// If colinear:           0
int Point::ccw(const Point& b, const Point& c) const
{
  int area2 = (b.x-x)*(c.y-y) - (b.y-y)*(c.x-x);
  if ( area2 < 0) return -1;
  if ( area2 > 0) return 1;
  return 0;
}

