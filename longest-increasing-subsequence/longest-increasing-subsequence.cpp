class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Check if the input vector is empty.
        if(nums.size() == 0)
            return 0;

        // Create a vector to store the elements of the LIS in a dynamic manner.
        vector<int> lis;
        
        // Initialize the LIS vector with the first element of the input vector.
        lis.push_back(nums[0]);

        // Iterate through the remaining elements of the input vector to build the LIS.
        for(int i = 1; i < nums.size(); ++i){
            // If the current element is greater than the last element in the LIS,
            // append it to the LIS as it contributes to the increasing subsequence.
            if(nums[i] > lis.back()){
                lis.push_back(nums[i]);
            }
            // If the current element is not greater, find the position where it can be inserted
            // using binary search and update the LIS accordingly.
            else{
                int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }

        // The size of the LIS vector represents the length of the Longest Increasing Subsequence.
        return lis.size();
    }
};
