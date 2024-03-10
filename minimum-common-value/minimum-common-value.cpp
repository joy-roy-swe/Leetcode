#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the first common element between two sorted arrays
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;  // Pointer for nums1
        int right = 0; // Pointer for nums2
        
        // Iterate until one of the pointers reaches the end of its array
        while (left < nums1.size() && right < nums2.size()) {
            // If the elements at the current positions are equal, return the common element
            if (nums1[left] == nums2[right])
                return nums1[left];
            // If the element in nums1 is smaller, move the left pointer to the next element in nums1
            else if (nums1[left] < nums2[right])
                left++;
            // If the element in nums2 is smaller, move the right pointer to the next element in nums2
            else
                right++;
        }
        // If no common element is found, return -1
        return -1;
    }
};

int main() {
    // Example usage of getCommon function
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};
    int common = sol.getCommon(nums1, nums2);
    if (common != -1) {
        cout << "The first common element is: " << common << endl;
    } else {
        cout << "No common element found." << endl;
    }
    return 0;
}
