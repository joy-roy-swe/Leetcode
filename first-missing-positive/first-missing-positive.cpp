#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Here's the optimized approach:

1. Iterate through the array and move each positive integer to its correct index (i.e., nums[i] should be at index i+1).
2. After rearranging the array, traverse it again to find the first index i where nums[i] != i+1. Return i+1 as the smallest missing positive integer.
3. If all integers are in their correct positions, return n+1.

This approach achieves O(1) space complexity as it modifies the input array in-place without using any extra space.
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

/*
Problem Statement:
Given an unsorted integer array, find the smallest missing positive integer.

Approach:
1. Sort the array to bring all positive integers together.
2. Initialize two variables: previous (to track the previous number encountered) and positive (to track the expected positive number).
3. Iterate through the sorted array:
   - If the current number is non-positive or equal to the previous number, skip to the next iteration.
   - If the current number is equal to the expected positive number, update previous and increment positive.
   - If the current number is not equal to the expected positive number, return the expected positive number.
4. If all positive integers are present in the array, return positive.

Time Complexity: O(nlogn), where n is the size of the input array due to sorting.
Space Complexity: O(1).
*/

/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int previous = 0;
        int positive = 1;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (num <= 0 || num == previous)
                continue;
            else if (num == positive) {
                previous = positive;
                ++positive;
            } else
                return positive;
        }
        return positive;
    }
};
*/


int main() {
    // Test the implementation
    vector<int> nums = {3, 4, -1, 1};
    Solution sol;
    cout << "Smallest missing positive integer: " << sol.firstMissingPositive(nums) << endl;
    return 0;
}
