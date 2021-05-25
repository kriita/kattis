#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int n;
double t;

double value(int n, double pot_max)
{
  if(n == 0) return pot_max;
  double prob = (1 + t) / 2;
  double pdf = 1 / (1 - t);
  double loss_rat = (1 << (n - 1)) / pot_max;

  if(loss_rat < t)
    pot_max *= prob;
  else
    pot_max = pdf * ((loss_rat- t) * (1 << (n - 1)) + (1 - loss_rat) * (1 + loss_rat) * pot_max / 2);
  return value(n - 1, pot_max);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    while(n)
    {
      int max_prize = 1 << n;
      double expect = value(n, max_prize);
      cout << fixed << setprecision(3) << expect << endl;
      cin >> n >> t;
    }

    return 0;
}
