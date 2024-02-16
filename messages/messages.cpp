/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : messages.cpp
 */

#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<utility>
#include<vector>

using namespace std;
using vi=vector<int>;

void fast()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

// Calculate the maximum number of non-overlapping substrings in the dicitonary
// that can be found in the message
void solve(const vector<string>& dictionary, const string& message)
{
  vector<pair<int,int> > positions;

  for (const string& word : dictionary)
  {
    size_t pos = message.find(word);
    while (pos != string::npos)
    {
      positions.push_back({pos, pos + word.size()});
      pos = message.find(word, pos + 1);
    }
  }

  // Sort positions by the end of the substring
  sort(positions.begin(), positions.end(),
      [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
      });

  // Greedily select the next substring that ends the earliest
  int count = 0;
  int last_end = -1;
  for (const auto& pos : positions)
    if (pos.first >= last_end)
    {
      last_end = pos.second;
      ++count;
    }

  cout << count << endl;
}

int main() 
{
  fast();

  // Load dictionary
  vector<string> dictionary;
  string word;
  while(cin >> word && word != "#")
    dictionary.push_back(word);

  // Load messages
  string complete_message;
  string partial_message;

  while(cin >> partial_message && partial_message != "#")
  {
    complete_message += partial_message;
    if (complete_message.back() == '|')
    {
      solve(dictionary, complete_message);
      complete_message.clear();
    }
  }

  return 0;
}

