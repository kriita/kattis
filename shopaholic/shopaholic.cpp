#include <functional>
#include <iostream>
#include <vector>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;
using vi=vector<int>;

int n;
int pi;
long long int tot;
vi p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pi;
        p.push_back(pi);
    }

    sort(p.begin(), p.end(), greater<int>());

    int d = p.size() / 3; // number of discounts possible

    for(int i = 0; i < d; ++i )
    {
        tot += p[ 3 * i + 2 ];
    }

    cout << tot << endl;

    return 0;
}
