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
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    bool isValid(TreeNode* root, TreeNode* max, TreeNode* min){
        if(root==NULL){
            return true;
        }
		// Using the same above logic
		//Just check if max or min-node is NULL, then follow it as true
        if((min==NULL || root->val > min->val) && (max==NULL || root->val < max->val)){
            return isValid(root->left, root, min) && isValid(root->right, max, root);
        }
        return false;
    }
};