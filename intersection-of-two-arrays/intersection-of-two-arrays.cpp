#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Create an unordered set from nums1 to store unique elements
        unordered_set<int> numset(nums1.begin(), nums1.end());
        
        // Vector to store the intersection elements
        vector<int> answer;
        
        // Iterate through nums2 to find intersection
        for(int num : nums2){
            // If the element is found in numset, add it to answer and remove it from numset
            if(numset.find(num) != numset.end()){
                answer.push_back(num);
                numset.erase(num);
            }
        }
        return answer;
    }
};

int main() {
    // Example usage of intersection function
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = sol.intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
