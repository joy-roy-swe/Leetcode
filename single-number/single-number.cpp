class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique_number = 0;
        for(int idx=0; idx<nums.size(); idx++){
            unique_number = unique_number^nums[idx];
        }
        return unique_number;
    }
};