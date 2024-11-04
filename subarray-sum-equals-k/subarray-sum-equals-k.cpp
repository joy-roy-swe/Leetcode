#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        std::unordered_map<int, int> prefixSumCount; // Store the frequency of prefix sums
        prefixSumCount[0] = 1; // Consider the empty prefix sum as 0 with frequency 1
        
        for (int num : nums) {
            sum += num; // Calculate cumulative sum
            
            // Check if there exists a subarray with sum equal to k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            
            // Update the frequency of the current prefix sum
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    std::cout << "Number of subarrays with sum " << k << ": " << solution.subarraySum(nums, k) << std::endl;
    return 0;
}
