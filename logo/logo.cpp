#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
#include "edge.h"
using namespace std;

double PI = 3.14159265358979323846;

int dist(Point p)
{
  double d = pow(p.x, 2) + pow(p.y, 2);
  d = sqrt(d);
  return round(d);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--)
    {
      Point end(0,0);
      int angle = 0;
      int c;
      cin >> c;
      while(c--)
      {
        string comm;
        int weight;
        cin >> comm >> weight;
        if(comm == "lt")
        {
          angle += weight;
        }
        else if(comm == "rt")
        {
          angle -= weight;
        }
        else if(comm == "fd")
        {
          end.x += cos(angle * (PI / 180)) * weight;
          end.y += sin(angle * (PI / 180)) * weight;
        }
        else
        {
          end.x -= cos(angle * (PI / 180)) * weight;
          end.y -= sin(angle * (PI / 180)) * weight;
        }
      }
      cout << dist(end) << endl;
    }

    return 0;
}
