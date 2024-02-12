/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : manber_myers.hpp
 * @brief   : Interface to Manber-Myers algorithm for constructing suffix array
 *
 * Example usage:
 *
 * #include "manber_myers.hpp"
 *
 * std::string s = "banana";
 * std::vector<int> suffixArray = constructSuffixArray(s);
 * for (int i = 0; i < (int)s.size(); ++i)
 * {
 *   std::cout << suffixArray[i] << " ";
 * }
 * std::cout << std::endl;
 *
 * Output: 5 3 1 0 4 2
 *
 */

#include<string>
#include<vector>

std::vector<int> constructSuffixArray(const std::string& str);
