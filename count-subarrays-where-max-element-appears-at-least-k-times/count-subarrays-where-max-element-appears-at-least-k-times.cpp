#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to count subarrays with at least K maximum elements
    long long countSubarrays(vector<int>& nums, int k) {
        // Find the maximum element in the array
        long long max_num = *max_element(nums.begin(), nums.end());
        
        // Initialize variables
        long long count = 0, left = 0, right = 0, ans = 0;
        
        // Slide the window over the array
        while(right < nums.size()) {
            // If the current element is the maximum element, increment the count
            if(nums[right] == max_num)
                count++;
            
            // If the count of maximum elements is greater than or equal to K
            while(count >= k) {
                // If the leftmost element of the window is the maximum element, decrement the count
                if(nums[left] == max_num)
                    count--;
                
                // Move the left pointer to the right and update the answer
                left++;
                ans += nums.size() - right;
            }
            
            // Move the right pointer to the right
            right++;
        }
        
        return ans; // Return the total count of subarrays
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {2, 1, 4, 1};
    int k = 3;
    cout << "Number of subarrays with at least " << k << " maximum elements: " << solution.countSubarrays(nums, k) << endl;

    return 0;
}
