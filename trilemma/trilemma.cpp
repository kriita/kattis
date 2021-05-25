#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

#include "edge.h"

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int t = 0; t < N; ++t)
    {
      vector<Point> points;
      int x, y;
  
      int M = 3;
      while(M)
      {
        cin >> x >> y;
        points.push_back(Point(x, y));
        --M;
      }

      if(points[0].ccw(points[1], points[2]) == 0)
      {
        cout << "Case #" << t + 1 << ": not a triangle" << endl;
        continue;
      }

      vector<Edge> edges;
      edges.push_back(Edge(points[0],points[1]));
      edges.push_back(Edge(points[1],points[2]));
      edges.push_back(Edge(points[2],points[0]));

      cout << "Case #" << t + 1 << ": ";

      bool scalene = !(edges[0].length() == edges[1].length() ||
                       edges[0].length() == edges[2].length() ||
                       edges[1].length() == edges[2].length());
      if(scalene)
        cout << "scalene ";
      else
        cout << "isosceles ";

      // Multiplying the scalar product between each pair of vectors
      // Scalar product = 0 => there exists a right angle, and the clause becomes = 0
      // Scalar product < 0 => there exists an obtuse angle and thus the clause becomes negative
      // Scalar product > 0 => acute angle. doesn't say much in and of itself but if no angle is right and none is obtuse the entire product is positive and distinct from the other outcomes
      long long int angle = ((points[1].x - points[0].x)*(points[2].x - points[0].x) + (points[1].y - points[0].y)*(points[2].y - points[0].y)) *
                  ((points[2].x - points[1].x)*(points[0].x - points[1].x) + (points[2].y - points[1].y)*(points[0].y - points[1].y)) *
                  ((points[0].x - points[2].x)*(points[1].x - points[2].x) + (points[0].y - points[2].y)*(points[1].y - points[2].y));
      if(angle == 0)
        cout << "right ";
      else if(angle > 0)
        cout << "acute ";
      else
        cout << "obtuse ";

      cout << "triangle" << endl;
    }
    
    return 0;
}
