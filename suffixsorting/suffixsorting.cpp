/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : suffixsorting.cpp
 * @brief   : Output the suffix array of a given string in stdin to stdout
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "manber_myers.hpp"

void fast()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
}


int main() 
{
  fast();

  std::string s;
  while(true)
  {
    std::getline(std::cin, s);
    if (s.empty())
      break;

    std::vector<int> suffixArray = constructSuffixArray(s);

    std::getline(std::cin, s);
    std::stringstream ss(s);
    
    int n;
    ss >> n;

    for (int i = 0; i < n; ++i)
    {
      int qi;
      ss >> qi;
      std::cout << suffixArray[qi] << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}

