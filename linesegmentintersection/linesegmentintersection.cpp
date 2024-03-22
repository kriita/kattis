/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : linesegmentintersection.cpp
 */

#include <iomanip>
#include <iostream>

#include "api/edge.h"

using namespace std;

void fast()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}


int main() 
{
  fast();

  int n;
  cin >> n;

  while (n--) {
    Edge a, b;
    cin >> a >> b;

    cout << setprecision(2) << fixed;
    vector<Point> v = a.intersection(b);
    if (v.size() > 0)
    {
      cout << v[0];
      for (int i = 1; i < v.size(); i++)
        cout << " " << v[i];
    }
    else
      cout << "none";
    cout << endl;
  }

  return 0;
}

