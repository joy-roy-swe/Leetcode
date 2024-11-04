/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function with the entire array range
        return helper(nums, 0, nums.size()-1);
    }
    // Helper function to recursively build a balanced binary search tree
    TreeNode* helper(vector<int>& nums, int low, int high) {
        // Base case: check if the range is valid
        if (low <= high) {
            // Calculate the middle index
            int mid = low + (high - low) / 2;

            // Create a new TreeNode with the value at the middle index
            TreeNode* root = new TreeNode(nums[mid]);

            // Recursively build the left and right subtrees
            root->left = helper(nums, low, mid-1);
            root->right = helper(nums, mid+1, high);

            // Return the root of the current subtree
            return root;
        }

        // Return NULL for invalid ranges
        return NULL;
    }
};