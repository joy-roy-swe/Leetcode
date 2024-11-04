#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/** unordered_map: 
* Using a unordered_map to record the occurrence of each number.
* With extra O(n) space, without modifying the input.
*
*    Time Complexity: O(n)
*    Space Complexity: O(n)
*/

// class Solution {
// public:
//     /**
//      * Function to find the duplicate element in the given array.
//      * 
//      * @param nums: The input array.
//      * @return The duplicate element found, or -1 if no duplicates are found.
//      */
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> map;
        
//         // Count the occurrences of each element in the array
//         for(int num : nums) {
//             map[num]++;
//         }
        
//         // Find the element with occurrence greater than 1
//         for(auto it : map) {
//             if(it.second > 1) {
//                 return it.first; // Return the duplicate element
//             }
//         }
        
//         return -1; // Return -1 if no duplicates are found
//     }
// };

/**
* Using Sorting:
* Sorting the array first, then use a loop from 111 to nnn.
* With extra O(nlogn) space, modifying the input.
*
*    Time Complexity: O(nlogn)
*    Space Complexity: O(logn)
*/

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int idx=1; idx<nums.size(); ++idx){
//             if(nums[idx] == nums[idx-1])
//                 return nums[idx];
//         }
//         return -1;
//     }
// };

/**
 * using two pointer:
 * With extra O(n) space, without modifying the input.
 *      Time Complexity: O(n)
 *      Space Complexity: O(1)

*/

class Solution {
public:
    /**
     * Function to find the duplicate element in the given array using two-pointer approach.
     * 
     * @param nums: The input array.
     * @return The duplicate element found, or -1 if no duplicates are found.
     */
    int findDuplicate(vector<int>& nums) {
        // Initialize the slow and fast pointers
        int slow = nums[0];
        int fast = nums[nums[0]];

        // Move slow and fast pointers until they meet
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Move slow pointer to the start and move both pointers at same pace until they meet
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Return the duplicate element
        return slow;
    }
};

int main() {
    // Example usage
    vector<int> nums = {1, 3, 4, 2, 2};

    Solution sol;
    int duplicate = sol.findDuplicate(nums);

    cout << "Duplicate element: " << duplicate << endl;

    return 0;
}
