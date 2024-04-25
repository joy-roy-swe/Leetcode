# Longest Ideal Subsequence

You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

- t is a subsequence of the string s.
- The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.

Return the length of the longest ideal string.

## Example 1:

**Input:**  
s = "acfgbd", k = 2

**Output:**  
4

**Explanation:**  
The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.  
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.

## Example 2:

**Input:**  
s = "abcd", k = 3

**Output:**  
4

**Explanation:**  
The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.

## Constraints:

- 1 <= s.length <= 105
- 0 <= k <= 25
- s consists of lowercase English letters.
