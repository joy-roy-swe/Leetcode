class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp_list = []
        if len(nums)<k:
            k = k%len(nums)

        if not k or len(nums) == 1:
            return
        
        for num in nums[-k:]:
            temp_list.append(num)
        left = len(nums)-k

        for num in nums[:left]:
            temp_list.append(num)
            
        for idx in range(len(temp_list)):
            nums[idx] = temp_list[idx]