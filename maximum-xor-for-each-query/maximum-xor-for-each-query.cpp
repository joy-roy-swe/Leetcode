#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer;
        vector<int> prefix_xor(n);
        prefix_xor[0] = nums[0];
        for(int i=1; i<n; ++i){
            prefix_xor[i] = prefix_xor[i-1] ^ nums[i];
        }
        int mask = (1<<maximumBit)-1;
        for(int i=n-1; i>=0; --i){
            answer.push_back(prefix_xor[i]^mask);
        }
        return answer;
    }
};