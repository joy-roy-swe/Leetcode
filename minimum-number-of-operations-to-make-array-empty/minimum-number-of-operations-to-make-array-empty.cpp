class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Map to store the frequency of each element in the array
        unordered_map<int, int> map;
        
        // Count the frequency of each element in the array
        for (auto i : nums) {
            map[i]++;
        }
        
        // Variable to store the total number of operations
        int count = 0;
        
        // Iterate through the frequency map
        for (auto current : map) {
            // If any element occurs only once, a harmonious array is not possible
            if (current.second == 1) {
                return -1;
            }
            
            // Calculate the number of operations required for each element to be harmonious
            count += current.second / 3;
            
            // If there is a remainder, one additional operation is needed
            if (current.second % 3) {
                count++;
            }
        }
        
        // Return the total number of operations
        return count;
    }
};
