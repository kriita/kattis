#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;

ll countZeros(ll q)
{
  ll zeros = 0;
  while(q)
  {
    zeros += ((q % 10) == 0);
    q /= 10;
  }
  return zeros;
}

// Calculates the total number of zeros in all numbers from 0 to n
ll countAllZeros(ll n)
{
  if (n == 0) return 0;
  if (n <= 10) return 1;
  ll q = n/10, rem = n%10;
  ll zeros = q + 10*(countAllZeros(q) - 1);
  if(rem > 0)
    zeros += rem*countZeros(q) + 1;
  return zeros;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n;
    while(true)
    {
      cin >> m >> n;
      if(m < 0) break;
      ll zeros = countAllZeros(n+1) - countAllZeros(m);

      cout << zeros << endl;
    }

    return 0;
}
