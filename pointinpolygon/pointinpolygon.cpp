#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>

#include "api/polygon.h"
using namespace std;

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  while(n)
  {
    Polygon poly;
    while(n--)
    {
      Point p;
      cin >> p.x >> p.y;
      poly.points.push_back(p);
    }

    int m;
    cin >> m;
    while(m--)
    {
      Point p;
      cin >> p.x >> p.y;

      int inside = poly.contains(p);

      if(inside == 1)
        cout << "in" << endl;
      else if(inside == 0)
        cout << "on" << endl;
      else
        cout << "out" << endl;
    }

    cin >> n;
  }

  return 0;
}
