/*
 * edge.cpp
 *
 * Author: Filip Jaredson
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
// Returns true if the point p lies on the edge
bool Edge::contains(const Point& p) const
{
  return p.distanceTo(u, v) == 0;
}

// length()
//
// Returns the euclidian length of the edge
double Edge::length() const
{
  return sqrt(pow((v.x - u.x),2) + pow((v.y - u.y), 2));
}

// operator<(e)
//
// Comparison operator compares the weights of the edges
bool Edge::operator<(const Edge& e) const
{
  return weight < e.weight;
}

