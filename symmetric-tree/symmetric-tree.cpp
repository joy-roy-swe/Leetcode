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
    bool isEqual(TreeNode*root1,TreeNode*root2){
        //if we have both root to nullptr then we will return true
        //else we will be returning false
        
        if(!root1 || !root2)
            return root1==root2;
        //if not null then we will check for the root1 and root2 values
        if(root1 && root2 && root1->val==root2->val){
        //we will check for the root1 left and root2 right because they will be on opposite sides
            return isEqual(root1->left,root2->right)&&isEqual(root1->right,root2->left);
        }
        //if root1 val not equal to root2 val then return false
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left,root->right);
    }
};