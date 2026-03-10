class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:

        for idx in range(len(nums)):
            num = nums[idx]
            nums[idx] = num ** 2
        nums.sort()
        return nums

        # left, right = 0, len(nums) - 1
        
        # # We need a separate result array if we solve it using two pointer
        # result = [0] * len(nums)
        
        # # Position pointer: fill from the END (largest first)
        # pos = len(nums) - 1
        
        # while left <= right:
        #     if abs(nums[left]) >= abs(nums[right]):
        #         # Left side has larger absolute value
        #         result[pos] = nums[left] ** 2
        #         left += 1       # ← move left pointer inward
        #     else:
        #         # Right side has larger absolute value
        #         result[pos] = nums[right] ** 2
        #         right -= 1      # ← move right pointer inward
        #     pos -= 1            # ← move position pointer backward
        
        # return result

        