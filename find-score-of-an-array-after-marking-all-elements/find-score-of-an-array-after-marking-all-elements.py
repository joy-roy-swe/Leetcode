from typing import List

class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        ordered_elements = [i for i in range(len(nums))]
        
        ordered_elements.sort(key=lambda x: (nums[x], x))
        
        for i in ordered_elements:
            if nums[i] != 0:
                score += nums[i]
                nums[i] = 0
                if i > 0:
                    nums[i - 1] = 0
                if i < len(nums) - 1:
                    nums[i + 1] = 0
        
        return score