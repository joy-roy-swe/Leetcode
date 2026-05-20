class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output_nums = []
        first_value = last_value = 1

        for idx in range(len(nums)):
            output_nums.append(first_value)
            first_value *= nums[idx]

        for idx in range(len(nums) - 1, -1, -1):
            output_nums[idx] *= last_value
            last_value *= nums[idx]
        
        return output_nums

        