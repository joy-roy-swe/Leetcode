from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        boolMap = [0] * len(nums)
        evenOdd = nums[0] % 2

        for i in range(1, len(nums)):
            if nums[i] % 2 != evenOdd:
                boolMap[i] = boolMap[i - 1]
            else:
                boolMap[i] = boolMap[i - 1] + 1
            evenOdd = nums[i]%2
        
        result = []
        for start, end in queries:
            result.append(boolMap[end] - boolMap[start] == 0)

        return result

        
if __name__ == "__main__":
    sol = Solution()
    print(sol.isArraySpecial([3, 4, 1, 2, 6], [[0, 4]]))
    print(sol.isArraySpecial([4, 3, 1, 6], [[0, 2], [2, 3]]))

