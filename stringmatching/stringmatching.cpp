// stringmatching.cpp
//
// Author: Filip Jaredson
// 
// API for string matching function, implementing the Knuth-Morris-Prath (KMP) algorithm.
//
// find(string pattern, string text) returns a vector of integers representing
// the starting positions of the occurences of the pattern in the text.
//
// Time complexity: O(text + pattern)

#include<iostream>
#include<string>
#include<vector>
#include<utility>

// Calculates the longest possible prefixes of the pattern which are also suffixes 
std::vector<int> LPS(std::string pattern)
{
    int m = pattern.length();
    std::vector<int> length(m,0);
    
    int i = 1; int j = 0;
    length[0] = 0;
    // Calculate length[i] for all other starting indexes
    while(i < m)
    {
        if (pattern[i] == pattern[j])
        {
            ++j;
            length[i] = j;
            ++i;
        }
        else
        {
            // Recursively check for shorter matching substrings
            if(j != 0)
                j = length[j - 1];
            else // Increment only if no matching substring
                ++i;
        }
    }
    return length;
}

// KMP search implementation, returns a vector containing the starting indices
// of the pattern in the text
std::vector<int> find(std::string pattern, std::string text)
{
    std::vector<int> length = LPS(pattern);
    std::vector<int> positions; // Vector containing starting indices of pattern in text
    
    int i = 0, j = 0;

    while(i < text.length())
    {
        if(pattern[j] == text[i])
        {
            ++i;
            ++j;
        }

        if (j == pattern.length())
        {
            positions.push_back(i - j);
            j = length[j - 1];
        }
        else if (i < text.length() && pattern[j] != text[i])
        {
            // If the next character mismatches, if possible look for a shorter
            // match otherwise check the next index.
            if(j != 0)
                j = length[j - 1];
            else
                ++i;
        }
    }

    return positions;
}

int main() 
{
    std::string pattern;
    std::string text;

    while(std::getline(std::cin, pattern))
    {   
        std::getline(std::cin, text);

        std::vector<int> positions = find(pattern, text);
        
        // Print results
        if(!positions.empty())
        {
            for(int i = 0; i < positions.size() - 1; ++i)
                std::cout << positions[i] << " ";
            std::cout << positions.back();
        }
        std::cout << std::endl;
    }
    return 0;
}
