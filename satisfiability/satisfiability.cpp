#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

vector<string> input_split(string s)
{
    stringstream ss;
    ss.str(s);
    string elem;
    vector<string> res;
    while(ss)
    {
        ss >> elem;
        res.push_back(elem);
    }
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    int n, m;
    while(t)
    {
        cin >> n >> m;
        cin.ignore();
        
        vector<vector<int>> clauses;

        for(int i = 0; i < m; ++i)
        {
            vector<int> subclause(n,0);
            string l;
            
            getline(cin, l);
            vector<string> elems = input_split(l);

            bool redundant = false;

            for(string elem : elems)
            {
                if(elem[0] == 'v')
                {
                    continue;
                }

                int sign = 1;
                if(elem[0] == '~')
                {
                    sign = -1;
                    elem = elem.substr(1,string::npos);
                }

                int elem_index = stoi(elem.substr(1,string::npos)) - 1;

                if(subclause[elem_index] * sign == -1)
                    redundant = true;

                subclause[elem_index] = sign;
            }

            if(!redundant)
                clauses.push_back(subclause);
        }

        bool satisfiable = false;
        for(int i = 0; i < 1 << n; ++i)
        {
            bool valid_lit = true;
            for(auto subclause : clauses)
            {
                bool valid_clause = false;
                for(int j = 0; j < n; ++j)
                {
                    // Check if there is a valid i v j, aka OR
                    if(subclause[j] == 1 && (i & (1 << j)) >= 1)
                    {
                        valid_clause = true;
                        break;
                    }
                    // Check if there is a valid -i v j or i v -j, aka NAND
                    else if(subclause[j] == -1 && (i & (1 << j)) == 0)
                    {
                        valid_clause = true;
                        break;
                    }
                }

                if(!valid_clause)
                {
                    valid_lit = false;
                    break;
                }
            }

            if(valid_lit)
            {
                satisfiable = true;
                break;
            }
        }

        cout << ((satisfiable) ? "satisfiable" : "unsatisfiable");
        cout << endl;

        --t;
    }

    return 0;
}
