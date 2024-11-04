#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    // Function to return the sorted squares of the input vector
    vector<int> sortedSquares(vector<int>& nums) {
        // Square each element in the vector
        for(int i = 0; i < nums.size(); ++i) {
            int num = square(nums[i]); // Get the square of the current number
            nums[i] = num; // Replace the original number with its square
        }
        
        // Sort the vector
        sort(nums.begin(), nums.end());
        
        return nums; // Return the sorted squares
    }
    
    // Function to calculate the square of a number
    int square(int num) {
        return num * num;
    }
};

int main() {
    // Example usage
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution solution;
    vector<int> result = solution.sortedSquares(nums);

    cout << "Sorted squares of the input vector: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
