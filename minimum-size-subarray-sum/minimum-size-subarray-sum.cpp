#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);

        // Calculate prefix sum array
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int minLength = INT_MAX;

        // Iterate through each index of the prefix sum array
        for (int i = 0; i < n; ++i) {
            // Perform binary search to find the rightmost index satisfying the condition
            int left = i + 1, right = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prefixSum[mid] - prefixSum[i] + nums[i] >= target) {
                    minLength = min(minLength, mid - i);
                    right = mid - 1; // Check for smaller subarrays
                } else {
                    left = mid + 1; // Expand the subarray
                }
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

int main() {
    // Example usage
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution sol;
    cout << "Minimal length of subarray: " << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}
