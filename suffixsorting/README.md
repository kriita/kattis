# Overview

A simple implementation of the Manber-Myers algorithm for suffix array
construction. The program reads a line containing a non-empty string _s_ of
length at most 100000 characters and constructs the suffix array for the string.
It then reads a line containing an integer _n_ followed by _n_ integers _q\_1,
q\_2, ... q\_n_ and outputs a line containing _n_ integers _p\_1, p\_2, ...,
p\_n_, where _p\_i_ is the starting position of the _q\_i_-th lexicographically
smallest substring of _s_. The time complexity of the algorithm is _O(n log n)_,
where n is the length of the input string.

Sample input:
```
popup
5 0 1 2 3 4
Popup
5 0 1 2 3 4
Suffixes are jolly fun, eh old chap?
7 35 3 18 33 26 6 2
```

Sample output:
```
1 4 0 2 3
0 1 4 2 3
17 18 19 20 21 22 23
```

