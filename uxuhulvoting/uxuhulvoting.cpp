#include <iostream>

using namespace std;

int dp[100][8];
int q[100][8];
int n, p, inp;

int stateAfterVote( int state, int vote )
{
    if ( vote == 0 )
    {
        if ( ( state & 4 ) == 4 )
        {
            return state - 4;
        }
        else
        {
            return state + 4;
        }
    }
    else if ( vote == 1 )
    {
        if ( ( state & 2 ) == 2 )
        {
            return state - 2;
        }
        else
        {
            return state + 2;
        }
    }
    else
    {
        if ( ( state & 1 ) == 1)
        {
            return state - 1;
        }
        else
        {
            return state + 1;
        }
    }
}

int solve ( int state, int priest )
{
    if ( priest == p ) // Recursion break
    {
        return state;
    }
    if ( dp[priest][state] != -1 ) // Don't recalculate dp values
    {
        return dp[priest][state];
    }

    int states[3];
    int next_priest = priest + 1;

    // Recursively calculate the state values depending on how the priest votes
    states[0] = solve(stateAfterVote(state, 0), next_priest);
    states[1] = solve(stateAfterVote(state, 1), next_priest);
    states[2] = solve(stateAfterVote(state, 2), next_priest);

    int best_state = 0;
    int best_val = -1;

    // Find which of the possible states the priest prioritizes the highest
    for ( int i = 0; i < 3; ++i )
    {
        if ( q[priest][states[i]] > best_val)
        {
            best_state = i;
            best_val = q[priest][states[i]];
        }
    }

    best_state = states[best_state];
    // Input into the dp matrix the move that the priest is going to make, i.e. its best state
    dp[priest][state] = best_state;

    return best_state;
}

string stringOfState ( int state )
{
    switch(state)
    {
        case 0: return "NNN";
        case 1: return "NNY";
        case 2: return "NYN";
        case 3: return "NYY";
        case 4: return "YNN";
        case 5: return "YNY";
        case 6: return "YYN";
        case 7: return "YYY";
        default: return "";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; // Number of rounds

    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < 100; ++j )
        {
            for ( int k = 0; k < 8; ++k )
            {
                dp[j][k] = -1; // Reset dp matrix
            }
        }

        cin >> p; // Number of priests

        for ( int j = 0; j < p; ++j ) for ( int k = 0; k < 8; ++k ) // loop through questions
        {
            cin >> inp;
            q[j][k] = 8 - inp; // Opnion is flipped for better dp code above
        }
        
        cout << stringOfState(solve(0,0)) << endl;
    }
    

    return 0;
}
