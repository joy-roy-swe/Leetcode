#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to count subarrays with elements between minK and maxK
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0; // Initialize the result variable
        bool minFound = false, maxFound = false; // Flags to indicate if minK and maxK have been found
        int start = 0, minStart = 0, maxStart = 0; // Start indices of the current subarray

        // Iterate over the array
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i]; // Current element

            // If the current element is outside the range [minK, maxK]
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i + 1; // Move the start index to the next element
            }

            // If the current element is equal to minK
            if (num == minK) {
                minFound = true;
                minStart = i; // Update the start index of minK
            }

            // If the current element is equal to maxK
            if (num == maxK) {
                maxFound = true;
                maxStart = i; // Update the start index of maxK
            }

            // If both minK and maxK have been found in the current subarray
            if (minFound && maxFound) {
                // Update the result by adding the length of the subarray
                res += (min(minStart, maxStart) - start + 1);
            }
        }
        return res; // Return the total count of subarrays
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int minK = 2, maxK = 4;
    cout << "Number of subarrays with elements between " << minK << " and " << maxK << ": "
         << solution.countSubarrays(nums, minK, maxK) << endl;

    return 0;
}
