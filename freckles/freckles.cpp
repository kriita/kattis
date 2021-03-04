#include<algorithm>
#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<typeinfo>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;

int find(vector<int>& d, int a) {
  if(d[a] == -1) {
    return a;
  }
  return d[a] = find(d, d[a]);
}

struct Point
{
  double x, y;
  bool operator <(const Point& p) const
  {
    return tie(x, y) < tie(p.x, p.y);
  }
  bool operator ==(const Point& p) const
  {
    return !(*this < p || p < *this);
  }

  bool operator !=(const Point& p) const
  {
    return *this < p || p < *this;
  }
};

struct Edge
{
  int u, v;
  double weight;
  bool operator <(const Edge& e) const
  {
    return weight < e.weight;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m; // number of test cases

  cin >> m;

  while(m--)
  {
    int n; // number of freckles
    cin >> n;

    vector<Edge> edges, result;
    vector<Point> freckles(n);

    for (int i = 0; i < n; ++i)
    {
      cin >> freckles[i].x >> freckles[i].y;
    }

    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        {
          double dist = sqrt(pow(freckles[i].x - freckles[j].x, 2) + pow(freckles[i].y - freckles[j].y, 2));
          edges.push_back({i, j, dist});
        }

    sort(edges.begin(), edges.end());

    vector<int> d(n, -1);
    double tot = 0.0;
    for (auto e : edges)
    {
      int loc_1 = find(d, e.u);
      int loc_2 = find(d, e.v);
      if ( loc_1 != loc_2 )
      {
        d[loc_1] = loc_2;
        tot += e.weight;
      }
    }
    cout << fixed;
    cout.precision(2);
    cout << tot << endl;
    if (m > 0)
    {
        cout << endl;
    }
  }
  return 0;
}
