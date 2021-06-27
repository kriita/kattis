/* DP setup:

Each DP solution starts off as "UNKNOWN" with a height -2 to indicate this,
then each solved subproblem receives one of the following states:

< "UP", h >,          meaning the next optimal move is up, reaching h in max height
< "DOWN", h >,        meaning the next optimal move is down, with h in max height
< "", 0 >,            meaning that the state is a valid final state of the problem
< "IMPOSSIBLE", -1 >, marking the state as invalid, not leading to a solution

*/

#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>

#define umap unordered_map
#define uset unordered_set

using namespace std;

pair<string,int> dp[40][1000];

pair<string,int> bad = make_pair("IMPOSSIBLE", -1);
pair<string,int> new_dp = make_pair("UNKNOWN", -2);

void fast()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

pair<string,int> best_path(int i, int h, vector<int> moves)
{
  if(i == moves.size()) // At final move
  {
    if(h == 0) return make_pair("",0);
    return bad;
  }

  if(dp[i][h].first != "UNKNOWN") // Don't re-explore
    return dp[i][h];

  pair<string,int> down = (h - moves[i] >= 0) ? best_path(i+1, h-moves[i], moves) : bad;
  pair<string,int> up = best_path(i+1, h+moves[i], moves);

  if(down.first != "IMPOSSIBLE" && ( down.second <= up.second || up.first == "IMPOSSIBLE"))
  {
    dp[i][h].first = "D" + down.first;
    dp[i][h].second = (h > down.second) ? h : down.second;
    return dp[i][h];
  }
  else if(up.first != "IMPOSSIBLE")
  {
    dp[i][h].first = "U" + up.first;
    dp[i][h].second = (h > up.second) ? h : up.second;
    return dp[i][h];
  }
  else
  {
    dp[i][h] = bad;
    return dp[i][h];
  }
}

int main() 
{
  fast();

  int N;
  cin >> N;

  while(N--)
  {
    int M;
    cin >> M;

    for(int i = 0; i < M; ++i)
      for(int h = 0; h < 1000; ++h)
        dp[i][h] = new_dp;

    vector<int> moves;
    int dist;

    while(M--)
    {
      cin >> dist;
      moves.push_back(dist);
    }

    string climb = best_path(0, 0, moves).first;
    cout << climb << endl;
  }
  return 0;
}

