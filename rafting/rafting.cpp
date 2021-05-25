#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>

#include "point.h"

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
      vector<Point> inner;
      vector<Point> outer;

      int ni, no;

      cin >> ni;
      while(ni--)
      {
        int x, y;
        cin >> x >> y;
        inner.push_back(Point(x, y));
      }

      cin >> no;
      while(no--)
      {
        int x, y;
        cin >> x >> y;
        outer.push_back(Point(x, y));
      }

      double max_diam = 1000;
      for(int o = 0; o < outer.size(); ++o)
      {
        Point p1 = outer[o];
        Point p2;
        if(o == outer.size() - 1)
        {
          p2 = outer[0];
        }
        else
        {
          p2 = outer[o+1];
        }

        for(Point i : inner)
          max_diam = min(max_diam, i.distanceTo(p1, p2));
      }
      cout << setprecision(8) << max_diam / 2 << endl;
    }

    return 0;
}
