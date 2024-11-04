#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Function to find the largest divisible subset of a given set of integers.
     * @param nums: The input vector of integers.
     * @return The largest divisible subset.
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {}; // If the input vector is empty, return an empty vector
        
        sort(nums.begin(), nums.end()); // Sort the input vector in non-decreasing order

        vector<vector<int>> dp(nums.size()); // Dynamic programming table to store subsets
        for (int i = 0; i < nums.size(); i++) {
            dp[i].push_back(nums[i]); // Initialize each subset with a single element
        }

        vector<int> answer; // Vector to store the largest divisible subset

        // Iterate through the elements in reverse order
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Check if the current number is divisible by the number in the subset at index j
                // and if adding it to the subset at index j would result in a larger subset
                if (nums[j] % nums[i] == 0 && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j]; // Update the subset at index i with the larger subset at index j
                    dp[i].push_back(nums[i]); // Add the current number to the subset at index i
                }
            }
            // Update the answer with the largest subset found so far
            if (dp[i].size() > answer.size()) {
                answer = dp[i];
            }
        }
        return answer; // Return the largest divisible subset
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 6, 8, 12};
    vector<int> result = sol.largestDivisibleSubset(nums);

    // Print the largest divisible subset
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
