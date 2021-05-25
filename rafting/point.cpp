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

// Calculates the distance between the point and the line segment spanned by p1 and p2
double Point::distanceTo(Point p1, Point p2)
{
  std::pair<double,double> p1p2(p2.x - p1.x, p2.y - p1.y);
  std::pair<double,double> p1p(x - p1.x, y - p1.y); 
  std::pair<double,double> p2p(x - p2.x, y - p2.y);
  
  // Dot products
  double p1p2_p1p = (p1p2.first * p1p.first + p1p2.second * p1p.second);
  if(p1p2_p1p <= 0) return sqrt(p1p.first * p1p.first + p1p.second * p1p.second);

  double p1p2_p2p = (p1p2.first * p2p.first + p1p2.second * p2p.second);
  if(p1p2_p2p >= 0) return sqrt(p2p.first * p2p.first + p2p.second * p2p.second);

  double p1p2_len = sqrt(p1p2.first * p1p2.first + p1p2.second * p1p2.second);
  return abs(p1p2.first * p1p.second - p1p2.second * p1p.first) / p1p2_len;
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

