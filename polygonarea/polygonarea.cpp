#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>

#include "api/polygon.h"

using namespace std;
using vi=vector<int>;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n != 0)
    {
      vector<Point> ps;
      while(n--)
      {
        int a, b;
        cin >> a >> b;
        ps.push_back(Point(a,b));
      }

      Polygon poly(ps);
      double area = poly.area();

      cout << fixed << showpoint << setprecision(1);
      if(area < 0)
        cout << "CW " << -area << endl;
      else
        cout << "CCW " << area << endl;

      cin >> n;
    }

    return 0;
}
