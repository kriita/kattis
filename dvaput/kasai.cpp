/**
 * @author  : kriita (thordask@gmail.com)
 * @file    : kasai.cpp
 * @brief   : Implementation of the Kasai algorithm for constructing the LCP
 *
 */

#include <algorithm>
#include <string>
#include <vector>

#include "kasai.hpp"
#include "manber_myers.hpp"

std::vector<int> kasai(const std::vector<int>& suffixArray, const std::string& str)
{
    int n = str.size();

    std::vector<int> lcp(n, 0), ranks(n, 0);

    for (int i = 0; i < n; ++i)
        ranks[suffixArray[i]] = i;

    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (ranks[i] == n - 1)
        {
            k = 0;
            continue;
        }

        int j = suffixArray[ranks[i] + 1];

        while (i + k < n &&
               j + k < n &&
               str[i + k] == str[j + k])
            k++;

        lcp[ranks[i]] = k;

        if (k > 0) --k;
    }

    return lcp;
}

