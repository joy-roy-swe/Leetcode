class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            int another = target-nums[i];
            if(map.find(another) != map.end()){
                return {map[another], i};
            }
            # here, add the key-value pair (vector value, vector index) to the map. The map now looks like this: {vector value : vector index}
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};
