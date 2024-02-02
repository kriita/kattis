# Overview

A simple implementation of the Knuth-Morris-Pratt algorithm for C++. The program
reads a text and pattern, searches the text for matches in the pattern using the
algorithm, and outputs the starting positions of the detected matches in a
vector. The time complexity of the algorithm is O(n + m), where n is the length
of the text and m is the length of the pattern.

Sample input 1:
p
Popup

Sample output 1:
2 4

Sample input 2:
peek a boo
you speek a bootiful language

Sample output 2:
5

