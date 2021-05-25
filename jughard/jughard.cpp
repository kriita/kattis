#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

// Calculates the greatest common factor of 2 ints using the euclidian algorithm
int GCF(int a, int b)
{
    if(a == 0 || a == b) return b;
    if(b == 0) return a;

    if(a > b)
        return GCF(a-b, b);
    return GCF(a, b-a);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T)
    {
        int a, b, d;
        cin >> a >> b >> d;

        int gcf = GCF(a, b);
        
        cout << ((d % gcf == 0) ? "Yes" : "No");
        cout << endl;

        --T;
    }
    return 0;
}
