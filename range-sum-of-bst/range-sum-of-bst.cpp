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

    /*
     * Function to calculate the sum of values in a binary search tree (BST)
     * that fall within the given range [low, high].
     *
     * Parameters:
     *   - root: The root of the binary search tree.
     *   - low: The lower bound of the range.
     *   - high: The upper bound of the range.
     *
     * Return:
     *   - The sum of values in the BST within the specified range.
     */
    int ans = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case: If the root is null, return the accumulated sum (initially set to 0).
        if (root == nullptr) {
            return ans;
        }

        // Check if the value of the current node is within the specified range [low, high].
        if (root->val >= low && root->val <= high) {
            // If yes, add the value to the accumulated sum.
            ans += root->val;
        }

        // Recursively traverse the left and right subtrees.
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);

        // Return the final accumulated sum.
        return ans;
    }
};
