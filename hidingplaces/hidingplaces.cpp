#include<algorithm>
#include<cmath>
#include<iostream>
#include<numeric>
#include<queue>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

#define BOARD_SIZE 8

bool visited[BOARD_SIZE][BOARD_SIZE];
pair<int, int> possibleMoves[BOARD_SIZE] = {make_pair(-1, -2), make_pair(1, -2), make_pair(2, -1), make_pair(2, 1), make_pair(-1, 2), make_pair(1, 2), make_pair(-2, -1), make_pair(-2, 1)};

struct pos
{
    int x, y, d;

    bool operator <(const pos& p) const
    {
        if(y != p.y) return y > p.y;
        return x < p.x;
    }
};

string pos_to_str(pos p)
{
    char file = p.x + 'a';
    char rank = p.y + '1';
    string pos;
    pos.push_back(file);
    pos.push_back(rank);
    return pos;
}

vector<pos> find_deepest(pos p)
{
    vector<pos> loc;
    queue<pos> q;

    q.push(p);
    visited[p.x][p.y] = true;
    
    int d = 0;

    while(!q.empty())
    {
        pos place = q.front();
        q.pop();

        if ( place.d > d )
        {
            d = place.d;
            loc.clear();
        }

        if ( place.d == d )
        {
            loc.push_back(place);
        }

        for(auto move : possibleMoves)
        {
            pos newpos;
            newpos.x = place.x + move.first;
            newpos.y = place.y + move.second;
            // Check if valid location
            if ( newpos.x > 7 || newpos.x < 0 || newpos.y > 7 || newpos.y < 0 )
                continue;
            if(!visited[newpos.x][newpos.y])
            {
                visited[newpos.x][newpos.y] = true;
                newpos.d = place.d + 1;
                q.push(newpos);
            }
        }
    }
    return loc;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string startstr;
    pos start;

    vector<pos> hidingLocations;

    for ( int i = 0; i < n; ++i )
    {
        cin >> startstr;

        start.x = startstr[0] - 'a';
        start.y = startstr[1] - '1';
        start.d = 0;

        for ( int j = 0; j < BOARD_SIZE; ++j )
            for (int k = 0; k < BOARD_SIZE; ++k )
                visited[j][k] = false;

        hidingLocations = find_deepest(start);

        sort(hidingLocations.begin(), hidingLocations.end());

        cout << hidingLocations[0].d;
        for ( auto loc : hidingLocations )
            cout << " " << pos_to_str(loc);
        
        cout << "\n";
    }

    return 0;
}