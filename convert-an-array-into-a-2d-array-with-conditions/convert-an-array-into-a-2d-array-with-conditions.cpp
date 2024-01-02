class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Create an unordered_map to store the frequency of each unique number.
        unordered_map<int, int> map;
        
        // Variable to keep track of the maximum frequency encountered.
        int count = 0;

        // Loop through the input vector to populate the frequency map and update the maximum frequency.
        for(auto n: nums){
            map[n]++;
            count = max(count, map[n]);
        }

        // Create a 2D vector to store the result matrix based on the maximum frequency.
        vector<vector<int>> ans(count);

        // Iterate through the frequency map to populate the result matrix.
        for(auto n: map){
            int number = n.first;     // Extract the unique number.
            int frequency = n.second;  // Extract its frequency.

            // Populate the rows of the result matrix with the number based on its frequency.
            for(int i = 0; i < frequency; i++){
                ans[i].push_back(number);
            }
        }

        // Return the resulting matrix.
        return ans;
    }
};
