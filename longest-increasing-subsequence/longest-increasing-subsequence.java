import java.util.*;
class Solution {
    public int lengthOfLIS(int[] nums) {
        // Check if the input array is empty
        if(nums.length == 0)
            return 0;

        //Create an array to store the element of LIS is a dynamic manner.
        int[] lis = new int[nums.length];
        Arrays.fill(lis, Integer.MAX_VALUE);

        // Intetialize the LIS array with the first element of the input array.
        lis[0] = nums[0];

        // Variable to keep track of the length of the LIS
        int len = 1;

        // Iterate through the remaining elements of the input array to build LIS.
        for(int i=1; i<nums.length; ++i){
            // If the current element is greater than the last element in the LIS
            // Append it to the LIS as it contributes to the increasing subsequence
            if(nums[i] > lis[len-1]){
                lis[len++] = nums[i];
            }
            // If the current element is not greater, find the position where it can be inserted.
            // Using binary search and update the LIS accordingly
            else{
                int idx = Arrays.binarySearch(lis, 0, len, nums[i]);
                if(idx<0){
                    idx = -idx - 1;
                }
                lis[idx] = nums[i];
            }
        }
        // The value of 'len' represents the length of the Longest Increasing Subsequence.
        return len;
    }
}