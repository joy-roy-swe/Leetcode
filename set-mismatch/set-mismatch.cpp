#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // Sorting the array to identify the duplicate and missing values
        sort(nums.begin(), nums.end());
        
        // Variables to store the duplicate and missing values
        int duplicate_value = 0;
        int total_sum = nums[0];  // Initialize with the first element
        
        // Iterate through the sorted array
        for(int idx = 1; idx < nums.size(); ++idx){
            if(nums[idx] == nums[idx-1]){
                // Found the duplicate value
                duplicate_value = nums[idx];
            }
            // Calculate the total sum of elements in the array
            total_sum += nums[idx];
        }
        
        // Calculate the expected sum for a sequence of consecutive integers from 1 to N
        int N = nums.size();
        int expected_sum = N * (N + 1) / 2;
        
        // Calculate the missing value using the expected sum and the total sum
        int missing_value = expected_sum - (total_sum - duplicate_value);
        
        // Return the result as a vector
        return {duplicate_value, missing_value};
    }
};
