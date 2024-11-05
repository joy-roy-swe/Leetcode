# /**
#  * @file rotate_string.py
#  * @author joy.roy
#  * @brief 
#  * @version 0.1
#  * @date 2024-11-05
#  * 
#  * @copyright Copyright (c) 2024
#  * 
#  * leetcode 796: Rotate String
#  */

## Solution Approach
# To determine if `s` can be rotated to match `goal`:
# 1. Check if `s` and `goal` have the same length. If not, return `false`.
# 2. Concatenate `s` with itself, creating `s + s`.
# 3. If `goal` is a substring of this concatenated string, then `s` can be rotated to become `goal`. Otherwise, it cannot.
# This approach works because if `goal` is a rotation of `s`, it must appear as a contiguous substring within `s + s`.

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # Check if both strings have the same length
        if len(s) != len(goal):
            return False

        # Concatenate s with itself to include all rotations
        concatenated = s + s

        # Check if goal is a substring of concatenated
        return goal in concatenated
        