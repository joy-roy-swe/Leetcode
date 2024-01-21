#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int money0 = 0;
        int money1 = 0;
        for(int i=0; i<nums.size(); ++i){
            int temp = max(nums[i]+money0, money1);
            money0 = money1;
            money1 = temp;
        }
        return money1;
    }
};