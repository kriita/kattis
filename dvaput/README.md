### Overview

Simple implementation of the Kasai algorithm to compute the LCP array of a
string. The program takes the length of a string as an integer, _L_, followed by
the string itself. The program then outputs the length of the longest substring
to appear at least twice in the string, the suffix in the LCP array that has
the longest LCP. The Kasai algorithm runs in _O(n)_ time complexity after the
suffix array has been constructed using the Manber-Myers algorithm in _O(n log
n)_ time complexity.

Sample Input 1:
```
11
sabcabcfabc

```

Sample Output 1:
```
3
```

Sample Input 2:
```
18
trutrutiktiktappop

```

Sample Output 2:
```
4
```

Sample Input 3:
```
6
abcdef

```

Sample Output 3:
```
0
```

