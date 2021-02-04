#include<iostream>
#include<string>
#include<vector>
using namespace std;
using vi=vector<int>;

string d;
string dout;
vi digits = { 0, 1, 2, 5, 9, 8, 6 };
vi changeBase(int n, int b)
{
    vi m = {};
    if(n == 0)
    {
        m.push_back(0);
        return m;
    }
    while(n)
    {
        m.push_back(n % b);
        n /= b;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(getline(cin,d))
    {
        dout = "";
        vi di = changeBase(stoi(d), 7);
        for(auto it = di.begin(); it != di.end(); ++it)
        {
            int dig = digits[*it];
            dout = dout + to_string(dig);
        }
        cout << dout << endl;
    }

    return 0;
}
