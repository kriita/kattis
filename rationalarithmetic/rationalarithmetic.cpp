/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : rationalarithmetic.cpp
 */

#include <iostream>

#include "rationalnumber.hpp"

using namespace std;

void fast()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}


int main() 
{
  fast();
  int t;
  cin >> t;

  while (t--)
  {
    RationalNumber a, b;
    char op;
    cin >> a >> op >> b;

    switch (op)
    {
      case '+':
        cout << a + b << endl;
        break;
      case '-':
        cout << a - b << endl;
        break;
      case '*':
        cout << a * b << endl;
        break;
      case '/':
        cout << a / b << endl;
        break;
    }
  }

  return 0;
}

