# Problem Type
Arithmetic

# Proposed solution
All possible valid numbers on the display are { 0, 1, 2, 5, 9, 8, 6 }, in order. When taking an input, change the base of the input number from 10 to 7 in order to properly sequence through this list (since it loops through 7 digits before repeating). Note that the input starts at 1. Then, iterate through each digit, backwards, matching each digit with its value in the new data set, and return the result.

For example, an input of 9 would be 12 in base 7. Iterating through the digits, backwards, would give us index 2, 2, and index 1, 1. Thus, the program would return the value 21.

