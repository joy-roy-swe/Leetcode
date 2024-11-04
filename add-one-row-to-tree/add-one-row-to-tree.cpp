#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * Add a row of nodes with a specified value at a given depth in a binary tree.
     * @param root The root of the binary tree
     * @param val The value to be inserted
     * @param depth The depth at which the row should be inserted
     * @return The root of the modified binary tree
     */
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, insert the new root node at the top
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        // Call the insertion helper function recursively
        return insertion(root, val, depth, 1);
    }

    /**
     * Recursively insert nodes with the specified value at the specified depth.
     * @param node The current node in the binary tree
     * @param val The value to be inserted
     * @param depth The depth at which the row should be inserted
     * @param level The current level in the binary tree
     * @return The current node after insertion
     */
    TreeNode* insertion(TreeNode* node, int val, int depth, int level) {
        // If the current node is null, return nullptr
        if (!node)
            return nullptr;

        // If the current level is one less than the target depth, perform insertion
        if (level == depth - 1) {
            // Store the original left and right subtrees
            TreeNode* temp_left = node->left;
            TreeNode* temp_right = node->right;
            
            // Create new nodes with the specified value and connect them
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);

            // Connect the new nodes with the original subtrees
            node->left->left = temp_left;
            node->right->right = temp_right;

            // Return the modified node
            return node;
        }

        // Recursively call the insertion function on the left and right subtrees
        node->left = insertion(node->left, val, depth, level + 1);
        node->right = insertion(node->right, val, depth, level + 1);

        // Return the current node after insertion
        return node;
    }
};

int main() {
    // Example usage
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    int val = 1, depth = 2;
    TreeNode* new_root = solution.addOneRow(root, val, depth);
    return 0;
}
