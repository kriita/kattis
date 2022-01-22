#ifndef POLYGON_H
#define POLYGON_H
#include<vector>
#include "point.h"

class Polygon
{
public:
  Polygon() = default;
  Polygon(std::vector<Point> _points);
  Polygon(std::vector<int> _x, std::vector<int> _y);

  std::vector<Point> points;

  double area() const;
  int contains(const Point& p) const;
  int contains(const double& x0, const double& y0) const;
  bool on(const Point& p) const;
};

#endif
