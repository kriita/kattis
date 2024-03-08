/*
 * polygon.cpp
 *
 * Author: Filip Jaredson
 */
#include<iostream>
#include "edge.h"

#include "polygon.h"

// Constructors
Polygon::Polygon(std::vector<Point> _points) : 
  points(_points) {}

Polygon::Polygon(std::vector<int> _x, std::vector<int> _y)
{
  for(int i = 0; i < _x.size(); ++i)
    points.push_back(Point(_x[i], _y[i]));
}

// area()
//
// Calculates the area of the polygon using the shoelace formula
//
// Note: area() returns a negative area if the contained points form a clockwise
// turn
// Complexity: O(# of points)
double Polygon::area() const
{ 
  int N = points.size();
  double A = (points[0].x + points.back().x)*(points[0].y - points.back().y)/2;
  for(int i = 0; i < N - 1; ++i)
    A += (points[i+1].x + points[i].x)*(points[i+1].y - points[i].y)/2;
  return A;
}

// contains(x0, y0)
//
// Check if the polygon contains the point (x0,y0), or if it's outside or on the
// border of the polygon. The solution is based on the ray intersection
// algorithm, using the number of crossings of a ray from the contained point to
// determine if the point is inside or outside of the polygon. For each edge in
// the polygon, a check is done to see if the point is on that edge. This
// captures the case where the point is on the border of the polygon.
//
// Returns 1 if it contains the point, 0 if it's on the border, and -1 if the
// point is outside the polygon.
//
// Worst case complexity: O(2 * # of points)
int Polygon::contains(const double& x0, const double& y0) const
{
  int N = points.size();
  int crossings = 0;

  for (int i = 0; i < N; ++i)
  {
    Point p1 = points[i];
    Point p2 = (i == points.size() - 1) ? points[0] : points[i+1];
    Edge e(p1, p2);

    if(e.contains(Point(x0, y0))) return 0;

    bool cond1   = (p1.x <= x0) && (x0 < p2.x);
    bool cond2   = (p2.x <= x0) && (x0 < p1.x);
    double slope = (p2.y - p1.y) / (p2.x - p1.x);
    bool above = (y0 > (slope * (x0 - p1.x) + p1.y));
    if ((cond1 || cond2) && above) ++crossings;
  }

  return (crossings % 2 != 0) ? 1 : -1;
}

// contains(p)
//
// Variant of the contains function for point object input
// Complexity: O(2 * # of points)
// Returns 1 if it contains the point, 0 if it's on the border, and -1 if the
// point is outside the polygon.
//
int Polygon::contains(const Point& p) const
{
  return contains(p.x, p.y);
}

// on(p)
//
// Checks if the point p is on the border of the Polygon
// Complexity: O(# of points)
// Returns true if the point is on the border, otherwise false
//
bool Polygon::on(const Point& p) const
{
  for(int i = 0; i < points.size(); ++i)
  {
    Point p1 = points[i];
    Point p2 = (i == points.size() - 1) ? points[0] : points[i+1];
    Edge e(p1, p2);
    if(e.contains(p)) return true;
  }
  return false;
}
