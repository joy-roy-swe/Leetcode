#include <vector>
using namespace std;

class Solution {
public:
    // Function to reverse the elements in a subarray [left, right]
    void reverse(vector<int>& nums, int left, int right){
        while(left <= right){
            // Swap elements at indices left and right
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            // Move indices towards the center
            right--;
            left++;
        }
    }

    // Function to rotate the array to the right by k steps
    void rotate(vector<int>& nums, int k) {
        // Ensure k is within the valid range of array size
        k = k % nums.size();
        
        // Reverse the entire array
        reverse(nums, 0, nums.size() - 1);
        
        // Reverse the first k elements
        reverse(nums, 0, k - 1);
        
        // Reverse the remaining elements after k
        reverse(nums, k, nums.size() - 1);
    }
};
