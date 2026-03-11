class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Normalize k in case it's >= len(nums)
        k = k%len(nums)

        if len(nums) == 0 or k == 0:
            return
        
        self.helper(nums, 0, len(nums)-1)
        self.helper(nums, 0, k-1)
        self.helper(nums, k, len(nums)-1)

    def helper(self, nums, start, end):
        while start<end:
            nums[start], nums[end] = nums[end], nums[start]
            start, end = start+1, end-1 