#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    // Function to find the minimum operations needed
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the input vector

        int operation = 0; // Initialize operation counter

        // Iterate through the sorted vector
        for(int i = 0; i < nums.size() && nums[i] < k; ++i) {
            operation++; // Increment operation counter for each element less than k
        }

        return operation; // Return the total operations
    }
};

int main() {
    // Example usage
    vector<int> nums = {1, 3, 5, 7, 9};
    int k = 6;
    Solution solution;
    int result = solution.minOperations(nums, k);

    cout << "Minimum operations needed: " << result << endl;

    return 0;
}
