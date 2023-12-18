class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // Create a new vector to store the concatenated elements
        vector<int> ans;

        // Loop through twice the size of the original vector
        for(int i = 0; i < 2 * n; i++) {
            // If the current index is less than the original size, append the element at that index
            if(i < n)
                ans.push_back(nums[i]);
            // If the current index exceeds the original size, append the element at (current index - original size)
            else
                ans.push_back(nums[i - n]);
        }

        // Return the concatenated vector
        return ans;
    }
};