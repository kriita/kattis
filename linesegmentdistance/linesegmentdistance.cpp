/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : linesegmentdistance.cpp
 */

#include<iomanip>
#include<iostream>

#include "api/edge.h"

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

  while(n--)
  {
    Edge e1, e2;
    std::cin >> e1 >> e2;

    std::cout << std::fixed << std::setprecision(2) << e1.distanceTo(e2) << std::endl;
  }
  return 0;
}

