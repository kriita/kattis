/*
 * polygon.cpp
 */
#include<iostream>
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
// Note: area() returns a negative area if the contained points form a clockwise turn
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
// Check if the polygon contains the point (x0,y0)
// Complexity: O(# of points)
bool Polygon::contains(const double& x0, const double& y0) const
{
  int N = points.size();
  int crossings = 0;
  for (int i = 0; i < N; ++i)
  {
    bool cond1   = (points[i].x <= x0) && (x0 < points[i+1].x);
    bool cond2   = (points[i+1].x <= x0) && (x0 < points[i].x  );
    double slope = (points[i+1].y - points[i].y) / (points[i+1].x - points[i].x);
    bool above = (y0 < slope * (x0 - points[i].x) + points[i].y);
    if ((cond1 || cond2) && above) crossings++;
  }
  return crossings % 2 != 0;
}

// Variant of the contains function for point object input
bool Polygon::contains(const Point& p) const
{
  return contains(p.x, p.y);
}

