#include<iostream>
#include<numeric>
#include<string>
#include<unordered_set>
using namespace std;
using uset = unordered_set<int>;

bool isPrime(int m)
{
    if(m == 1) return false;
    bool prime = true;
    for(int i = 2; i <= m / 2; ++i)
    {
        if(m % i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

int squareSum(int m)
{
    int sum = 0;
    while (m)
    {
        sum += (m % 10) * (m % 10);
        m /= 10;
    }
    return sum;
}

bool happyPrime(int m)
{
    if(!isPrime(m)) return false;
    uset visited;
    while(true)
    {
        m = squareSum(m);
        if(m == 1)
            return true;
        if(visited.find(m) != visited.end())
            return false;
        visited.insert(m);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int P;
    cin >> P;

    while(P)
    {
        int K, m;
        cin >> K >> m;

        cout << K << " " << m << " ";

        cout << (happyPrime(m) ? "YES" : "NO");

        cout << endl;

        --P;
    }

    return 0;
}
