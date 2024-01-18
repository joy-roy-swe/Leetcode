#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        unordered_map<int, int> map;  // Hash map to store the frequency of each element
        for (int it = 0; it < nums.size(); ++it) {
            map[nums[it]]++;  // Increment the frequency of the current element in the map
            
            // Check if the current element appears more than 2 times
            if (map[nums[it]] > 2) {
                nums.erase(nums.begin() + it);  // Remove the current element from the vector
                --it;  // Decrement the iterator to reevaluate the current position
            }
        }
        return nums.size();  // Return the size of the modified vector
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int newSize = solution.removeDuplicates(nums);

    // Display the modified vector
    for (int i = 0; i < newSize; ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}