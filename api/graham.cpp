#include<algorithm>
#include<iostream>
#include<numeric>
#include<string>
#include<unordered_set>
#include<utility>
#include<vector>

#include "graham.h"

Point start_p;

void swap(Point& p1, Point& p2)
{
  Point tmp = p1;
  p1 = p2;
  p2 = tmp; }

bool polarComp(Point p1, Point p2)
{
  int dir = start_p.ccw(p1, p2);
  if(dir == 0)
  {
    Edge e1(start_p, p1);
    Edge e2(start_p, p2);
    return (e2.length() > e1.length());
  }
  return dir != -1;
}

std::vector<Point> grahamScan(std::vector<Point> points)
{
  int min_y = points[0].y, min_p = 0;
  for(int i = 1; i < points.size(); ++i)
    if(points[i].y < min_y || (points[i].y == min_y && points[i].x < points[min_p].x))
    {
      min_y = points[i].y;
      min_p = i;
    }

  swap(points[0], points[min_p]);
  start_p = points[0];
  std::sort(points.begin(), points.end(), polarComp);

  int i = 0;
  while(i < points.size() - 2)
  {
    int dir = points[i].ccw(points[i+1], points[i+2]);
    if(dir > 0)
    {
      ++i;
    }
    else
    {
      points.erase(points.begin() + i + 1);
      if(i > 0) --i;
    }
  }
  return points;
}
