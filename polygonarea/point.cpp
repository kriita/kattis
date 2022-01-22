/*
 * Simple point class
 *
 * Author: Filip Jaredson
 */
#include<cmath>
#include<tuple>
#include "point.h"

// Point(x, y)
// Constructor for a point (x,y)
//
Point::Point(double _x,double _y) :
  x(_x),y(_y) 
{} 

// Point.angle()
// returns the angle to the point in radians
//
double Point::angle() const
{
  return atan(y/x);
}

// Point.angleTo(p)
// returns the angle between the point and p in radians
//
double Point::angleTo(const Point& p) const
{
  return atan((p.y-y)/(p.x-x));
}

// Point.length()
// returns the distance to the point from the origin
//
double Point::length() const
{
  Point origin(0,0);
  return distanceTo(origin);
}

// Point.distanceTo(p)
// returns the distance to the point p
//
double Point::distanceTo(const Point& p) const
{
  double dx = x - p.x;
  double dy = y - p.y;
  return sqrt(dx*dx + dy*dy);
}

// Point.distanceTo(p1,p2)
// Returns the distance between the point and the line segment spanned by p1 and
// p2.
//
double Point::distanceTo(const Point& p1, const Point& p2) const
{
  Point p1p2(p2.x - p1.x, p2.y - p1.y);
  Point p1p(x - p1.x, y - p1.y); 
  Point p2p(x - p2.x, y - p2.y);

  if(p1p2.dot(p1p) <= 0) return p1p.length();

  if(p1p2.dot(p2p) >= 0) return p2p.length();

  return abs(p1p2.cross(p1p))/p1p2.length();
}

// Point.cross(p)
// Returns the cross product with the point p
// 
double Point::cross(const Point& p) const
{
  return (x * p.y - y * p.x);
}

// Point.dot(p)
// Returns the dot product with the point p
//
double Point::dot(const Point& p) const
{
  return(x * p.x + y * p.y);
}

// Point.ccw(b, c)
// Checks if the three-point-sequence makes a clockwise turn, counter-clockwise
// turn, or are colinear.
// Return values:
// ..clockwise:          1
// ..counter-clockwise: -1
// ..colinear:           0
//
int Point::ccw(const Point& b, const Point& c) const
{
  int area2 = (b.x-x)*(c.y-y) - (b.y-y)*(c.x-x);
  if ( area2 < 0) return -1;
  if ( area2 > 0) return 1;
  return 0;
}

// Point.operator<(p)
// Returns true if the point has smaller x value than p, or equal x but smaller
// y than p.
//
bool Point::operator<(const Point& p) const
{
  return std::tie(x, y) < std::tie(p.x, p.y);
}

// Point.operator==(p)
// Returns true if the points have equal coordinates.
bool Point::operator==(const Point& p) const
{
  return !(*this < p || p < *this);
}

// Point.operator!=(p)
// Returns true if the points do not have equal coordinates.
bool Point::operator!=(const Point& p) const
{
  return *this < p || p < *this;
}

