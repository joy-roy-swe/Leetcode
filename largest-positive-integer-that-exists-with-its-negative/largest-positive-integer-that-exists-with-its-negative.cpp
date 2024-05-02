#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * Find the maximum value of the sum of two elements in a sorted vector that equals zero.
     * @param nums The input vector of integers
     * @return The maximum value among the second elements of pairs that sum to zero,
     *         or -1 if no such pair exists.
     */
    int findMaxK(std::vector<int>& nums) {
        // Sort the input vector
        sort(nums.begin(), nums.end());
        // Initialize two pointers, left and right, to the start and end of the vector
        int left = 0, right = nums.size() - 1;
        // Initialize a variable to store the maximum value found
        int maxValue = INT_MIN;
        // Loop until the left pointer is less than the right pointer
        while (left < right) {
            // Calculate the sum of the current elements pointed to by left and right
            int sum = nums[left] + nums[right];
            // If the sum equals zero
            if (sum == 0) {
                // Update the maximum value with the maximum of the current value and the value pointed to by right
                maxValue = std::max(maxValue, nums[right]);
                // Move both pointers inward
                left++;
                right--;
            } else if (sum < 0) { // If the sum is less than zero, move the left pointer to the right
                left++;
            } else { // If the sum is greater than zero, move the right pointer to the left
                right--;
            }
        }
        // Return the maximum value found, or -1 if no such pair exists
        return maxValue != INT_MIN ? maxValue : -1;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {-3, -2, -1, 0, 1, 2, 3};
    int result = solution.findMaxK(nums);
    std::cout << "The maximum value among pairs that sum to zero is: " << result << std::endl;
    return 0;
}
