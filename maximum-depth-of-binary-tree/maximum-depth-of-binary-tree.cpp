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
    int maxDepth(TreeNode* root) {
        // Base case: if the root is NULL, the depth is 0
        if (root == NULL)
            return 0;

        // Recursive calls to find the maximum depth of the left and right subtrees
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        // Return the maximum depth of the current subtree, considering left and right depths
        return max(lh, rh) + 1;
    }
};