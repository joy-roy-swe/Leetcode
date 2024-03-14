#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to count the number of subarrays with a given sum
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count; // Map to store the count of prefix sums
        count[0] = 1; // Initialize count of prefix sum 0 as 1
        int curr_sum = 0; // Initialize current sum
        int total_subarrays = 0; // Initialize total subarrays with the given sum

        // Traverse through the array and calculate prefix sums
        for (int num : nums) {
            curr_sum += num; // Update current sum
            // If there exists a prefix sum such that (current_sum - goal), update total_subarrays
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++; // Increment count of current sum
        }

        return total_subarrays; // Return the total count of subarrays with the given sum
    }
};

int main() {
    Solution sol;

    // Example usage of the numSubarraysWithSum function
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = sol.numSubarraysWithSum(nums, goal);
    cout << "Number of subarrays with sum " << goal << " is: " << result << endl;

    return 0;
}
