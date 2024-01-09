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
    /**
     * Check if the leaf sequence of two binary trees is similar.
     *
     * Parameters:
     *   - root1: The root of the first binary tree.
     *   - root2: The root of the second binary tree.
     *
     * Return:
     *   - True if the leaf sequences are similar, false otherwise.
     */
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSequence1, leafSequence2;

        // Get the leaf nodes of the first binary tree
        getLeafNodes(root1, leafSequence1);

        // Get the leaf nodes of the second binary tree
        getLeafNodes(root2, leafSequence2);

        // Check if the leaf sequences are identical
        return leafSequence1 == leafSequence2;
    }

private:
    /**
     * Helper function to recursively get the leaf nodes of a binary tree.
     *
     * Parameters:
     *   - node: The current node in the binary tree.
     *   - leafNodes: A vector to store the leaf nodes.
     */
    void getLeafNodes(TreeNode* node, vector<int>& leafNodes) {
        if (!node) {
            return;
        }

        // If the current node is a leaf node, add its value to the list
        if (!node->left && !node->right) {
            leafNodes.push_back(node->val);
            return;
        } else {
            // Recursively get leaf nodes for the left and right subtrees
            getLeafNodes(node->left, leafNodes);
            getLeafNodes(node->right, leafNodes);
        }
    }
};
