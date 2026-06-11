class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)

        # Cyclic sort to place numbers in their correct index
        i = 0
        while i < n:
            correct_idx = nums[i] - 1
            # Only swap if nums[i] is in the range [1, n] and not already in the correct position
            if 1 <= nums[i] <= n and nums[i] != nums[correct_idx]:
                nums[i], nums[correct_idx] = nums[correct_idx], nums[i]
            else:
                i += 1

        # Now find the first index where the number is not correct
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1  # The smallest missing positive number

        # If all positions are correct, return n + 1
        return n + 1