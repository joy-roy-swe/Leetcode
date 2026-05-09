class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for idx, val in enumerate(nums):
            if target - val in hashmap:
                return [hashmap[target-val],idx]
            hashmap[val]=idx