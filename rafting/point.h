#ifndef POINT_H
#define POINT_H

class Point
{
public:
  Point(double _x = 0, double _y = 0);
  ~Point() = default;

  double x, y;

  double distanceTo(Point p);
  double distanceTo(Point p1, Point p2);
  int ccw(const Point& b, const Point& c) const;

  bool operator<(const Point& p) const;
  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;
};

#endif
