# /**
#  * @file find_if_array_can_be_sorted.py
#  * @author joy.roy
#  * @brief 
#  * @version 0.1
#  * @date 2024-11-06
#  * 
#  * @copyright Copyright (c) 2024
#  * 
#  * leetcode 3011. Find if Array Can Be Sorted
#  */

from typing import List
class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(1, n):
            for j in range(0, n-i):
                if nums[j]<=nums[j+1]:
                    continue
                else:
                    if nums[j].bit_count() == nums[j+1].bit_count():
                        nums[j], nums[j+1] = nums[j+1], nums[j]
                    else:
                        return False
        return True

