#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. Sort the array to group duplicate elements together.
2. Iterate through the sorted array.
3. If the current element is equal to the previous one, it's a duplicate.
4. Add the duplicate element to the answer vector.
5. Return the answer vector containing all duplicates.
*/

vector<int> findDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sorting the array
    vector<int> answer; // Vector to store duplicates
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i - 1]) { // Check for duplicates
            answer.emplace_back(nums[i]); // Add duplicate to answer vector
        }
    } 
    return answer; // Return vector containing duplicates
}

int main() {
    // Test the function
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    cout << "Duplicates: ";
    for(int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
