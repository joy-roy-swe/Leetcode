/**
 * @file find_if_array_can_be-sorted.cpp
 * @author joy.roy
 * @brief 
 * @version 0.1
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 2024
 * 
 * leetcode 3011. Find if Array Can Be Sorted
 */


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    bool canSortArray(vector<int>& nums){
        int n = nums.size();
        for(int i=1; i<n; ++i){
            for(int j=0; j<n-i; ++j){
                if(nums[j]<=nums[j+1])
                    continue;
                else{
                    if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1]))
                        swap(nums[j], nums[j+1]);
                    else return false;
                }
            }
        }
        return true;
    }
};