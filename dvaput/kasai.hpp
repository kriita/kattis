/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : kasai.hpp
 * @brief   : Interface for an implementaiton of the Kasai algorithm for
 *            constructing the LCP array from the suffix array.
 * 
 * Example usage:
 *
 * #include "kasai.hpp"
 * #include "manber_myers.hpp"
 *
 * std::string s = "banana";
 * std::vector<int> suffixArray = constructSuffixArray(s);
 * std::vector<int> lcpArray = kasai(suffixArray, s);
 * for (int i = 0; i < (int)s.size(); ++i)
 * {
 *   std::cout << lcpArray[i] << " ";
 * }
 * std::cout << std::endl;
 *
 * Output: 1 3 0 0 2 0
 *
 */

#ifndef KASAI_HPP
#define KASAI_HPP

#include <vector>

/**
 * @brief   : Construct the LCP array from the suffix array.
 * @param   : suffixArray - The suffix array.
 * @param   : str  - The string from which the suffix array was constructed.
 * @return  : The LCP array.
 */

std::vector<int> kasai(const std::vector<int>& suffixArray, const std::string& str);

#endif // KASAI_HPP

