/**
 * @author  : Filip Jaredson (fila057@student.liu.se)
 * @file    : knuth_morris_prath.cpp
 */

#include<string>
#include<vector>

#include "knuth_morris_pratt.hpp"

// Calculate longest prefix suffix of string pattern
std::vector<int> calcLps(const std::string &pattern) 
{
  std::vector<int> lps(pattern.size(), 0);

  int len = 0;
  for (int i = 1; i < (int)pattern.size(); ++i) 
  {
    if (pattern[i] == pattern[len]) 
      lps[i] = ++len;
    else 
      if (len != 0) 
      {
        len = lps[len - 1];
        --i;
      }
  }

  return lps;
}

// Find all occurences of a pattern in text using the Knuth-Morris-Pratt
// algorithm
std::vector<int> kmpSearch(const std::string &pattern, const std::string &text) 
{
  std::vector<int> lps = calcLps(pattern);
  std::vector<int> patternPositions;

  int i = 0, j = 0;
  while (i < (int)text.size()) 
  {
    if (text[i] == pattern[j]) 
    {
      ++i;
      ++j;
    }

    if (j == (int)pattern.size()) 
    {
      patternPositions.push_back(i - j);
      j = lps[j - 1]; // Continue searching for more occurences from lps
    } 
    else 
      if (i < (int)text.size() && text[i] != pattern[j]) 
      {
        if (j != 0) 
          j = lps[j - 1];
        else 
          ++i;
      }
  }

  return patternPositions;
}

