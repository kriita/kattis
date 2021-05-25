/*
 * edge.cpp
 */
#include<algorithm>
#include<cmath>

#include "edge.h"

// Standard constructor
Edge::Edge(Point _u, Point _v, double _weight) :
  u(_u), v(_v), weight(_weight) {}

// Checks if the edge intersects with edge e2
bool Edge::intersect(const Edge& e2) const
{
  int test1 = u.ccw(v, e2.u) * u.ccw(v, e2.v);
  int test2 = e2.u.ccw(e2.v, u) * e2.u.ccw(e2.v, v);
  return !(test1 > 0) && !(test2 > 0);
}

// on(p)
//
// Checks if the point p lies on the edge
bool Edge::contains(const Point& p) const
{
  return (p.x <= std::max(u.x, v.x) && p.x >= std::min(u.x, v.x) &&
          p.y <= std::max(u.y, v.y) && p.y >= std::min(u.y, v.y));
}

// Returns the euclidian length of the edge
double Edge::length() const
{
  return sqrt(pow((v.x - u.x),2) + pow((v.y - u.y), 2));
}

// Comparison operator for weights of edges
bool Edge::operator<(const Edge& e) const
{
  return weight < e.weight;
}

