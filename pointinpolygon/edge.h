#ifndef EDGE_H
#define EDGE_H
#include "point.h"

class Edge
{
public:
  Edge(Point _u, Point _v, double _weight = 0);
  ~Edge() = default;

  Point u, v;
  double weight;
  
  bool intersect(const Edge& e) const;
  bool contains(const Point& p) const;
  double length() const;

  bool operator<(const Edge& e) const;
};

#endif
