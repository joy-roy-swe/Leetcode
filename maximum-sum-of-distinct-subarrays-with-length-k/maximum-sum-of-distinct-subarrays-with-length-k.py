from typing import List

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        start = 0
        maxSum = 0
        windowSum = 0
        seen = set()  # To track unique elements in the current window

        for end in range(len(nums)):
            # If the element is already in the window, shrink the window
            while nums[end] in seen:
                seen.remove(nums[start])
                windowSum -= nums[start]
                start += 1
            
            # Add the current element to the window
            seen.add(nums[end])
            windowSum += nums[end]

            # If the window size equals `k`, update the max sum
            if end - start + 1 == k:
                maxSum = max(maxSum, windowSum)
                
                # Remove the oldest element to make room for the next iteration
                seen.remove(nums[start])
                windowSum -= nums[start]
                start += 1

        return maxSum
