class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0
        right = 0
        for left in range(len(nums)):
            if nums[left] == 0:
                break
        right = left+1
        while right < len(nums):
            if nums[right] != 0 and left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left+=1
            right+=1