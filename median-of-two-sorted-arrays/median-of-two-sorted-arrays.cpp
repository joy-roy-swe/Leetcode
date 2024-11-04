#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge nums2 into nums1
        for(int num : nums2){
            nums1.emplace_back(num);
        }
        // Sort the merged array
        sort(nums1.begin(), nums1.end());
        
        double median;
        int mid;
        // Calculate median based on the size of the merged array
        if(nums1.size() % 2 == 0){
            mid = nums1.size() / 2;
            median = (double)(nums1[mid] + nums1[mid - 1]) / 2;
        } else {
            mid = nums1.size() / 2;
            median = nums1[mid];
        }
        return median;
    }
};

int main() {
    // Example usage
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution solution;
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median of the merged sorted arrays: " << median << endl;
    return 0;
}
