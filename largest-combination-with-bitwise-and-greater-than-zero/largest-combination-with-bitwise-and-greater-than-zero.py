# /**
#  * @file largest-combination-with-bitwise-and-greater-than-zero.cpp
#  * @author joy.roy
#  * @brief 
#  * @version 0.1
#  * @date 2024-11-05
#  * 
#  * @copyright Copyright (c) 2024
#  * 
#  * leetcode 796: Rotate String
#  */

from typing import List
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(1 for candidate in candidates if candidate & (1 << i))
            ans = max(ans, cnt)
        return ans

