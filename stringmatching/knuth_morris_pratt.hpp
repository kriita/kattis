/**
 * @author  : Filip Jaredson (fila057@student.liu.se)
 * @file    : knuth_morris_prath.cpp
 *
 * Example usage:
 *
 * #include "knuth_morris_prath.hpp"
 *
 * std::vector<int> result = kmpSearch("text", "pattern");
 *
 * for (int i = 0; i < result.size(); i++)
 * {
 *   std::cout << result[i] << std::endl;
 * }
 *
 * This will print the positions of the pattern in the text.
 */

#include <string>
#include <vector>

/** Find all occurences of pattern in text using KMP algorithm
 *
 * @param text The text to search in
 * @param pattern The pattern to search for
 *
 */

std::vector<int> kmpSearch(const std::string &text, const std::string &pattern);
