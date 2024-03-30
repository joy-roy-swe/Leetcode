#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to count subarrays with exactly K distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int counter = 0, left = 0, middle = 0;
        unordered_map<int, int> num_frequency;

        // Slide the window over the array
        for(int right = 0; right < nums.size(); ++right) {
            num_frequency[nums[right]]++;

            // If the number of distinct elements exceeds K
            while(num_frequency.size() > k) {
                num_frequency[nums[middle]]--;

                // Remove the element from the map if its frequency becomes 0
                if(num_frequency[nums[middle]] == 0)
                    num_frequency.erase(nums[middle]);
                middle++;
                left = middle;
            }

            // Slide the window to the right until there are exactly K distinct elements
            while(num_frequency[nums[middle]] > 1) {
                num_frequency[nums[middle]]--;
                middle++;
            }

            // If there are exactly K distinct elements in the window, update the counter
            if(num_frequency.size() == k) {
                counter += middle - left + 1;
            }
        }
        return counter; // Return the total count of subarrays
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Number of subarrays with exactly " << k << " distinct elements: " << solution.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}
