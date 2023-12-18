class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Sort the array in ascending order
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

        // Calculate the product difference using the maximum and minimum elements
        int n = sortedNums.size();
        int maxDiff = (sortedNums[n-1]*sortedNums[n-2]) - (sortedNums[1]*sortedNums[0]);
        return maxDiff;
    }
};