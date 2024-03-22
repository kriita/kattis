/*
 * Simple point class
 *
 * Author: Filip Jaredson
 */
#include<cmath>
#include<iostream>
#include<tuple>
#include "point.h"

// Point(x, y)
// Constructor for a point (x,y)
//
Point::Point(long double _x,long double _y) :
  x(_x),y(_y) 
{} 

// Point.angle()
// returns the angle to the point in radians
//
long double Point::angle() const
{
  return atan(y/x);
}

// Point.angleTo(p)
// returns the angle between the point and p in radians
//
long double Point::angleTo(const Point& p) const
{
  return atan((p.y-y)/(p.x-x));
}

// Point.length()
// returns the distance to the point from the origin
//
long double Point::length() const
{
  Point origin(0,0);
  return distanceTo(origin);
}

// Point.distanceTo(p)
// returns the distance to the point p
//
long double Point::distanceTo(const Point& p) const
{
  long double dx = x - p.x;
  long double dy = y - p.y;
  return sqrt(dx*dx + dy*dy);
}

// Point.distanceTo(p1,p2)
// Returns the distance between the point and the line segment spanned by p1 and
// p2.
//
long double Point::distanceTo(const Point& p1, const Point& p2) const
{
  // If p1 == p2, the distance is the distance to p1
  if(p1 == p2)
    return distanceTo(p1);

  // Calculate the projection of the point on the line spanned by p1 and p2
  Point a = p2 - p1;
  Point b = *this - p1;
  long double proj = a.dot(b) / a.dot(a);

  if(proj < 0)
    return distanceTo(p1);

  if(proj > 1)
    return distanceTo(p2);

  return distanceTo(p1 + a * proj);
}

// Point.cross(p)
// Returns the cross product with the point p
// 
long double Point::cross(const Point& p) const
{
  return (x * p.y - y * p.x);
}

// Point.dot(p)
// Returns the dot product with the point p
//
long double Point::dot(const Point& p) const
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
  Point ab(b.x - x, b.y - y);
  Point ac(c.x - x, c.y - y);
  long double cross = ab.cross(ac);
  if(cross > 0) return 1;
  if(cross < 0) return -1;
  return 0;
}

// Point.operator+(p)
// Returns the point that is the sum of the point and p.
//
Point Point::operator+(const Point& p) const
{
  return Point(x + p.x, y + p.y);
}

// Point.operator-(p)
// Returns the point that is the difference of the point and p.
// 
Point Point::operator-(const Point& p) const
{
  return Point(x - p.x, y - p.y);
}

// Point.operator*(c)
// Returns the point that is the product of the point and the scalar c.
//
Point Point::operator*(long double c) const
{
  return Point(x * c, y * c);
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

// Point.operator>>(is, p)
// Reads a point from the input stream is
std::istream& operator>>(std::istream& is, Point& p)
{
  is >> p.x >> p.y;
  return is;
}

// Point.operator<<(os, p)
// Writes the point to the output stream os
std::ostream& operator<<(std::ostream& os, const Point& p)
{
  os << p.x << " " << p.y;
  return os;
}
