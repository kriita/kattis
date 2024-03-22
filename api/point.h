#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
  Point(long double _x = 0, long double _y = 0);

  long double x, y;

  long double angle() const;
  long double angleTo(const Point& p) const;

  long double length() const;
  long double distanceTo(const Point& p) const;
  long double distanceTo(const Point& p1, const Point& p2) const;

  long double cross(const Point& p) const;
  long double dot(const Point& p) const;
  int ccw(const Point& b, const Point& c) const;

  Point operator+(const Point& p) const;
  Point operator-(const Point& p) const;
  Point operator*(long double c) const;
  bool operator<(const Point& p) const;
  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;

  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif
