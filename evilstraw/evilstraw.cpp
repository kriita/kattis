#include<cmath>
#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<utility>
using namespace std;
using vi=vector<int>;

// Returns if it's possible to make a palindrome out of the string word
bool possible_palindrome( string word )
{
    vi alphabet(26,0);
    for ( auto let : word )
        ++alphabet[ let - 'a' ];

    int odds = 0;
    for ( auto let : alphabet )
    {
        if ( let % 2 != 0 )
        {
            ++odds;
        }
    }

    if ( (odds && word.length() % 2 == 0) ||
         odds > 1)
        return false;
    
    return true;
}

// Creates a palindrome of a word that is "palindromable"
pair<string,int> palindrome( string word )
{
    int swaps = 0;
    int left = 0;
    int right = word.length() - 1;

    while (left < right)
    {
        if (word[left] != word[right])
        {
            int loc = right;
            // Find matching letter
            while ( word[loc] != word[left] &&
                    loc != left )
            {
                --loc;
            }
            if (loc == left)
            {
                swap( word[left], word[left + 1] );
                ++swaps;
                continue;
            }
            else
            {
                while (loc < right)
                {
                    swap(word[loc], word[loc+1]);
                    ++loc;
                    ++swaps;
                }
            }
        }
        ++left;
        --right;
    }

    pair<string,int> pal = make_pair(word, swaps);
    return pal;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    string word;
    while (cases)
    {
        cin >> word;
        if (possible_palindrome(word))
        {
            cout << palindrome(word).second << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        --cases;
    }

    return 0;
}
