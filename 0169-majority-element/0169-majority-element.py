class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        current_element = nums[0]
        current_count = 1

        for num in nums[1:]:
            if current_element != num:
                current_count-=1
            else:
                current_count+=1
            
            if current_count <= 0:
                current_element = num
                current_count = 1
            
        return current_element