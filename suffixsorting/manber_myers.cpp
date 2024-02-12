/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : manber_myers.cpp
 * @brief   : Implementation of Manber-Myers algorithm for constructing suffix array
 */

#include "manber_myers.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Construct the suffix array of a given string using the Manber-Myers algorithm
// Time complexity: O(n log n)
// where n is the length of the string
// Returns the suffix array of the given string as a vector of indices
// corresponding to the suffixes in lexicographical order
std::vector<int> constructSuffixArray(const std::string& str)
{
  int n = str.size();
  std::vector<int> suffixArray(n), rank(n), tempRank(n);

  // Initialize the suffix array and rank
  for (int i = 0; i < n; i++)
  {
    suffixArray[i] = i;
    rank[i] = str[i];
  }

  for (int k = 1; k < n; k *= 2)
  {
    // Compares two suffixes based on their rank and the rank of the suffix k
    // characters ahead, returns true if the first suffix (a) has smaller rank
    auto cmp_suffix = [&](int a, int b)
    {
      if (rank[a] != rank[b])
        return rank[a] < rank[b];
      a += k;
      b += k;
      if (a < n && b < n)
        return rank[a] < rank[b];
      return a > b;
    };

    std::sort(suffixArray.begin(), suffixArray.end(), cmp_suffix);

    tempRank[suffixArray[0]] = 0;
    for (int i = 1, r = 0; i < n; ++i)
    {
      if (cmp_suffix(suffixArray[i - 1], suffixArray[i]))
        r++;
      tempRank[suffixArray[i]] = r;
    }
    rank = tempRank;
  }

  return suffixArray;
}
