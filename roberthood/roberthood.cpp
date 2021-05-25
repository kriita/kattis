#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>

#include "graham.h"

using namespace std;
using vi=vector<int>;

double distsq(Point p1, Point p2)
{
  return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C, x, y;
    vector<Point> hits;
    cin >> C;
    while(C--)
    {
      cin >> x >> y;
      hits.push_back(Point(x,y));
    }
    hits = grahamScan(hits);
    double dist2 = 0;

    for(int i = 0; i < hits.size(); ++i)
      for(int j = i + 1; j < hits.size(); ++j)
        dist2 = max(distsq(hits[i], hits[j]), dist2);

    cout << fixed << setprecision(7) << sqrt(dist2) << endl;

    return 0;
}
