#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Sort the array first
        int left = 0, right = nums.size() - 1;
        int count = 0;
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                count++;  // Found a valid pair
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > k) {
                right--;  // Sum is too large, move the right pointer
            }
            else {
                left++;  // Sum is too small, move the left pointer
            }
        }
        return count;
    }
};

int main() {
    Solution sol;  // Create an instance of Solution class
    vector<int> nums = {1, 2, 3, 4, 5, 6};  // Example array
    int k = 7;  // Example value for k

    int result = sol.maxOperations(nums, k);  // Call the function
    cout << "Max operations: " << result << endl;  // Output the result

    return 0;
}
