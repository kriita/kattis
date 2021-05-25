/*
 * edge.cpp
 */
#include<cmath>

#include "edge.h"
#include "point.h"

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

// Returns the euclidian length of the edge

double Edge::length()
{
  double dist = pow((v.x - u.x),2) + pow((v.y - u.y), 2);
  dist = sqrt(dist);
  return dist;
}

// Comparison operator for weights of edges
bool Edge::operator<(const Edge& e) const
{
  return weight < e.weight;
}

