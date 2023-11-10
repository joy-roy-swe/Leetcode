class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            int another = target-nums[i];
            if(map.find(another) != map.end()){
                return {map[another], i};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};