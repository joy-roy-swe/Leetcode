#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // If k is less than or equal to 1, no subarray will have a product less than k

        int product = 1; // Initialize product of the current window
        int counter = 0; // Counter to count the number of subarrays with product less than k
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right]; // Expand the window by multiplying with the new element

            // Shrink the window until the product is less than k
            while (product >= k) {
                product /= nums[left]; // Remove the leftmost element from the window
                left++; // Move the left pointer to the right
            }

            // Add the number of subarrays with product less than k ending at the current index
            counter += right - left + 1;
        }

        return counter; // Return the total count of subarrays
    }
};

int main() {
    // Example usage
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    Solution sol;
    cout << "Number of subarrays with product less than " << k << ": " << sol.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}
