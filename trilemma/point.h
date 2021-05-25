#ifndef POINT_H
#define POINT_H

class Point
{
public:
  Point() = default;
  Point(double _x = 0, double _y = 0);
  ~Point() = default;

  double x, y;

  double distanceTo(Point p);
  int ccw(const Point& b, const Point& c) const;

  bool operator<(const Point& p) const;
  bool operator==(const Point& p) const;
  bool operator!=(const Point& p) const;
};

#endif
