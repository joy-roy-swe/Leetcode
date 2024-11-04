#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the majority element in a given array
    int majorityElement(vector<int>& nums) {
        int majority = 0; // Counter for the current majority element
        int value = 0; // Variable to store the majority element value
        for(int num :nums){
            if(majority == 0){ // If the counter is zero, set the current element as the majority element candidate
                majority++;
                value = num;
            }
            else if(num == value){ // If the current element is equal to the majority element candidate, increment the counter
                majority++;
            }
            else{ // If the current element is different from the majority element candidate, decrement the counter
                majority--;
            }
        }
        return value; // Return the majority element candidate
    }
};

int main() {
    // Example usage of the majorityElement function
    Solution solution;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; // Example input array
    int majority = solution.majorityElement(nums); // Find the majority element
    cout << "Majority element: " << majority << endl; // Output the result
    return 0;
}
