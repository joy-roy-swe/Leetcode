/**
 * @file rotate_string.cpp
 * @author joy.roy
 * @brief 
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 * leetcode 796: Rotate String
 */



// ## Solution Approach

// To determine if `s` can be rotated to match `goal`:
// 1. Check if `s` and `goal` have the same length. If not, return `false`.
// 2. Concatenate `s` with itself, creating `s + s`.
// 3. If `goal` is a substring of this concatenated string, then `s` can be rotated to become `goal`. Otherwise, it cannot.
// This approach works because if `goal` is a rotation of `s`, it must appear as a contiguous substring within `s + s`.

#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if both strings are of the same length
        if (s.size() != goal.size()) 
            return false;

        // Concatenate s with itself to include all rotations
        string str = s + s;

        // Check if goal is a substring of str
        return str.find(goal) != string::npos;
    }
};