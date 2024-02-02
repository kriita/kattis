/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : {{FILE}}
 */

#include <iostream>

#include "knuth_morris_pratt.hpp"

void fast()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
}


int main() 
{
  fast();

  std::string pattern;
  std::string text;

  while (std::getline(std::cin, pattern)) {
    std::getline(std::cin, text);

    std::vector<int> matches = kmpSearch(pattern, text);

    for (int i = 0; i < (int)matches.size(); i++)
      std::cout << matches[i] << " ";

    std::cout << std::endl;
  }

  return 0;
}

