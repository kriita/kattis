#include<cmath>
#include<cstdio>
#include<iostream>
#include<numeric>
#include<stack>
#include<string>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
using vi=vector<int>;

int H, W, g, w, h;
int p = -1;
char map[50][50];
stack<int> to_process;
unordered_set<int> processed;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(scanf("%i %i", &W, &H) == 2)
    {
        for(int h=0; h < H; ++h)
        {
            scanf("%s", map[h]);
            if (p < 0)
            {
                for (int w = 0; w < W; ++w)
                {
                    if (map[h][w] == 'P')
                    {
                        p = 100 * h + w;
                    }
                }
            }
        }
        
        to_process.push(p);

        while(!to_process.empty())
        {
            p = to_process.top();
            to_process.pop();

            if (processed.find(p) != processed.end()) continue;
            processed.insert(p);

            h = p / 100;
            w = p % 100;

            if (map[h][w] == 'G') ++g;

            if( (map[h-1][w] == 'T') ||
                (map[h+1][w] == 'T') ||
                (map[h][w-1] == 'T') ||
                (map[h][w+1] == 'T') ) continue;


            w -= 1;
            if( (processed.find(100 * h + w) == processed.end()) &&
                (map[h][w] != '#') )
                to_process.push(100 * h + w);
            w += 1;
            h -=1;
            if( (processed.find(100 * h + w) == processed.end()) &&
                (map[h][w] != '#') )
                to_process.push(100 * h + w);
            h += 1;
            w += 1;
            if( (processed.find(100 * h + w) == processed.end()) &&
                (map[h][w] != '#') )
                to_process.push(100 * h + w);
            w -= 1;
            h += 1;
            if( (processed.find(100 * h + w) == processed.end()) &&
                (map[h][w] != '#') )
                to_process.push(100 * h + w);
        }

        cout << g << endl;

        return 0;
    }
}
