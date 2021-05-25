#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

// Returns a prime factorization of x
vector<int> prime_factors(int x)
{
    vector<int> factors;

    int i = 2;
    while(i <= sqrt(x))
    {
        if(x % i == 0)
        {
            factors.push_back(i);
            x /= i;
        }
        else
        {
            ++i;
        }
    }
    if(x > 1)
        factors.push_back(x);

    return factors;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;

    while(cin >> x && x != 4)
    {
        int t = 0;
        while(true)
        {
            ++t;
            
            vector<int> primeFactors = prime_factors(x);
            if(primeFactors.size() == 1)
            {
                cout << x << " " << t << endl;
                break;
            }
            else
            {
                x = accumulate(primeFactors.begin(), primeFactors.end(), 0);
            }
        }
    }

    return 0;
}
