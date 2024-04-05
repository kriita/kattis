/*
 * edge.cpp
 *
 * Author: Filip Jaredson
 */
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>

#include "edge.h"
#include "point.h"

// Standard constructor
Edge::Edge(Point _u, Point _v, long double _weight) :
  u(_u), v(_v), weight(_weight)
{
  if (v < u)
    std::swap(u, v);
}

// ccw(p)
// Checks if the point p is to the left of the edge
// Returns 1 if p is to the left of the edge, -1 if p is to the right of the
// edge, and 0 if p is on the edge
int Edge::ccw(const Point& p) const
{
  return u.ccw(p, v);
}

// contains(p)
//
// Returns true if the point p lies on the edge
bool Edge::contains(const Point& p) const
{
  return p.distanceTo(u, v) == 0;
}

// singlePointIntersect(e2)
// Checks if the edge intersects at a single point with the edge e2
// Returns true if the edges intersect at a single point, false otherwise
bool Edge::singlePointIntersect(const Edge& e2) const
{
  // If one of the edges is a single point, the edges only intersect if the
  // point is on the other edge
  if (u == v)
    return e2.contains(u);
  if (e2.u == e2.v)
    return contains(e2.u);

  int test1 = ccw(e2.u) * ccw(e2.v);
  int test2 = e2.ccw(u) * e2.ccw(v);

  // If the edges are colinear, check if they intersect at a single point
  if (test1 == 0 && test2 == 0)
    return v == e2.u || u == e2.v || v == e2.v || u == e2.u;
  
  return test1 <= 0 && test2 <= 0;
}

// overlap(e2)
// Checks if the edge is collinear and overlaps with the edge e2
// Returns true if the edges overlap, false otherwise
bool Edge::overlap(const Edge& e2) const
{
  if (singlePointIntersect(e2))
    return true;


  // The edge cannot overlap one is a single point without an intersect
  if (u == v || e2.u == e2.v)
    return false;

  int ccw1 = ccw(e2.u);
  int ccw2 = ccw(e2.v);
  int ccw3 = e2.ccw(u);
  int ccw4 = e2.ccw(v);

  // The edges are collinear
  if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0)
    // The edges overlap if the endpoints of one edge are contained in the other
    return contains(e2.u) || contains(e2.v) || e2.contains(u) || e2.contains(v);
  
  return false;
}

// length()
//
// Returns the euclidian length of the edge
long double Edge::length() const
{
  return sqrt(pow((v.x - u.x),2) + pow((v.y - u.y), 2));
}

// distanceTo(p)
// Returns the euclidian distance from the point p to the edge
long double Edge::distanceTo(const Point& p) const
{
  return p.distanceTo(u, v);
}

// distanceTo(e)
// Returns the euclidian distance from the edge to the edge e
long double Edge::distanceTo(const Edge& e) const
{
  // If the lines intersect, the distance is 0
  if (singlePointIntersect(e))
    return 0;

  std::vector<long double> distances;
  distances.push_back(distanceTo(e.u));
  distances.push_back(distanceTo(e.v));
  distances.push_back(e.distanceTo(u));
  distances.push_back(e.distanceTo(v));

  long double dist = std::numeric_limits<long double>::max();
  for (size_t i = 0; i < distances.size(); ++i)
    dist = std::min(dist, distances[i]);

  return dist;
}

// intersection(e)
//
// If the edges do not intersect, an empty vector is returned
// If the edges intersect at a single point, a vector with one point is returned
// If the edges are collinear, a vector with two points is returned
std::vector<Point> Edge::intersection(const Edge& e) const
{
  std::vector<Point> result;
  
  // Check if the edges intersect
  if (singlePointIntersect(e))
  {
    if (ccw(e.u) == 0)
    {
      result.push_back(e.u);
      return result;
    }

    if (ccw(e.v) == 0)
    {
      result.push_back(e.v);
      return result;
    }

    if (e.ccw(u) == 0)
    {
      result.push_back(u);
      return result;
    }

    if (e.ccw(v) == 0)
    {
      result.push_back(v);
      return result;
    }

    // The edges intersect at a single point
    long double t = (e.u - u).cross(e.v - e.u) / (v - u).cross(e.v - e.u);
    Point intersection = u + (v - u) * t;
    result.push_back(intersection);
    return result;
  }

  // The edges are collinear and overlap
  if (overlap(e))
  {
    Point p1 = std::max(u, e.u);
    Point p2 = std::min(v, e.v);
    result.push_back(p1);
    result.push_back(p2);
    return result;
  }

  // The edges intersect at a single point
  return result;
}

// operator<(e)
//
// Comparison operator compares the weights of the edges
bool Edge::operator<(const Edge& e) const
{
  return weight < e.weight;
}

// operator==(e)
//
// Equality operator compares the weights of the edges
//
// Returns true if the weights and the points of the edges are equal
bool Edge::operator==(const Edge& e) const
{
  return weight == e.weight && u == e.u && v == e.v;
}

// operator>>(is, e)
//
// Reads the edge from the input stream
std::istream& operator>>(std::istream& is, Edge& e)
{
  is >> e.u >> e.v;
  return is;
}
