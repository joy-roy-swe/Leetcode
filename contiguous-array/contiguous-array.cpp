#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // HashMap to store the difference between counts of zeros and ones along with their indices
        unordered_map<int, int> hashmap;
        int zeros = 0, ones = 0, max_len = 0;

        // Initialize the hashmap with the initial difference of 0 at index -1
        hashmap[0] = -1;

        // Traverse through the array and update counts of zeros and ones
        for(int idx = 0; idx < nums.size(); ++idx) {
            nums[idx] == 0 ? ++zeros : ++ones;
            int diff = zeros - ones;

            // If the difference exists in the hashmap, update the maximum length
            if(hashmap.count(diff)) {
                max_len = max(max_len, idx - hashmap[diff]);
            } else {
                // If the difference is encountered for the first time, store it along with its index
                hashmap[diff] = idx;
            }
        }
        return max_len;
    }
};

int main() {
    // Example usage
    vector<int> nums = {0, 1, 0, 1, 0, 1};
    Solution solution;
    int max_length = solution.findMaxLength(nums);
    cout << "Maximum length of contiguous subarray with equal number of 0s and 1s: " << max_length << endl;
    return 0;
}
