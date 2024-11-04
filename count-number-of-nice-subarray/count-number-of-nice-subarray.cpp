#include <iostream>
#include <vector>

using namespace std;

int numberOfNiceSubarrays(vector<int>& nums, int k) {
    int result=0, odd=0;
    int left=0, middle=0;
    for(int right=0; right<nums.size(); ++right){
        if(nums[right]%2!=0)
            ++odd;
        
        while(odd>k){
            if(nums[left]%2!=0)
                odd -= 1;
            ++left;
            middle = left;
        }
        if(odd == k){
            while(nums[middle]%2==0)
                ++middle;
            result += (middle-left)+1;
                
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << "Output: " << numberOfNiceSubarrays(nums1, k1) << endl;  // Output: 2

    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << "Output: " << numberOfNiceSubarrays(nums2, k2) << endl;  // Output: 0

    vector<int> nums3 = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k3 = 2;
    cout << "Output: " << numberOfNiceSubarrays(nums3, k3) << endl;  // Output: 16

    return 0;
}
