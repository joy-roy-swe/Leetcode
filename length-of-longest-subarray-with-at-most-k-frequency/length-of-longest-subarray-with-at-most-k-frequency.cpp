#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to find the maximum length of subarrays with at most K distinct elements
    int maxSubarrayLength(vector<int>& nums, int k) {
        int windowStart = 0; // Initialize the start of the window
        int maxLength = 0; // Initialize the maximum length of subarray
        unordered_map<int, int> map; // Map to store the frequency of elements in the current window

        // Loop through the array to extend the window
        for(int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
            map[nums[windowEnd]]++; // Increment the frequency of the current element

            // Shrink the window until the number of distinct elements exceeds K
            while(map.size() > k) {
                map[nums[windowStart]]--; // Decrement the frequency of the element at the start of the window
                if(map[nums[windowStart]] == 0) {
                    map.erase(nums[windowStart]); // Remove the element if its frequency becomes zero
                }
                windowStart++; // Move the window's start to the right
            }

            // Update the maximum length of subarray
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength; // Return the maximum length of subarray
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Maximum length of subarrays with at most " << k << " distinct elements: " << solution.maxSubarrayLength(nums, k) << endl;

    return 0;
}
