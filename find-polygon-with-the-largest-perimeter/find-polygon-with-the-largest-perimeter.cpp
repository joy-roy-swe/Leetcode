#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the largest perimeter possible using elements from a given vector
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0; // Variable to store the sum of elements
        long long answer = -1; // Variable to store the largest perimeter

        sort(nums.begin(), nums.end()); // Sort the elements in ascending order

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < sum) { // If the current element can form a triangle with previous elements
                answer = nums[i] + sum; // Update the largest perimeter
            }
            sum += nums[i]; // Update the sum of elements
        }
        return answer; // Return the largest perimeter
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class

    // Example input vector
    vector<int> nums = {3, 4, 6, 2, 7, 8, 5};

    // Find the largest perimeter possible using the input vector
    long long result = solution.largestPerimeter(nums);

    // Output the result
    cout << "Largest Perimeter: " << result << endl;

    return 0;
}
