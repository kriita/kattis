#ifndef EDGE_H
#define EDGE_H
#include<vector>
#include "point.h"

class Polygon
{
public:
  Polygon(std::vector<Point> v);
  Polygon(std::vector<int> _x, std::vector<int> _y);

  std::vector<Point> points;

  double area() const;
  bool contains(const double& x0, const double& y0) const;
  bool contains(const Point& p) const;
};

#endif
