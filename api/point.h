#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
public:
  Point(double _x = 0, double _y = 0);

  double x, y;

  double angle() const;
  double angleTo(const Point& p) const;

  double length() const;
  double distanceTo(const Point& p) const;
  double distanceTo(const Point& p1, const Point& p2) const;

  double cross(const Point& p) const;
  double dot(const Point& p) const;
  int ccw(const Point& b, const Point& c) const;

  Point operator+(const Point& p) const;
  Point operator-(const Point& p) const;
  Point operator*(double c) const;
  bool operator<(const Point& p) const;
  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;

  friend std::istream& operator>>(std::istream& is, Point& p);
  friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif
