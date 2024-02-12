/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : dvaput.cpp
 * @brief   : Find the longest substring that appears at least twice in a string
 *
 */

#include <algorithm>
#include <limits>
#include <iostream>
#include <string>

#include "kasai.hpp"
#include "manber_myers.hpp"

void fast()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
}


int main() 
{
  fast();

  int n;
  std::cin >> n;
  std::cin.ignore(1, '\n');

  std::string s;
  std::getline(std::cin, s);

  std::vector<int> sa = constructSuffixArray(s);
  std::vector<int> lcp = kasai(sa, s);

  int maxLcp = 0;
  for (int i = 0; i < (int)lcp.size(); ++i) {
    maxLcp = std::max(maxLcp, lcp[i]);
  }

  std::cout << maxLcp << std::endl;

  return 0;
}

