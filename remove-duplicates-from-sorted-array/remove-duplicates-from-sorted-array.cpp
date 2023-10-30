class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int key=1;
        int num=1;
        while(num<nums.size()){
            if(nums[num-1]!=nums[num]){
                nums[key]=nums[num];
                key++;
            }
            num++;
        }
        return key;
    }
};