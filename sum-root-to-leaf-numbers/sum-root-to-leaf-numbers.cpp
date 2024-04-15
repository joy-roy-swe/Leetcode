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
     * Find the sum of all root-to-leaf numbers.
     * @param root The root of the binary tree
     * @return The sum of all root-to-leaf numbers
     */
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    /**
     * Depth-first search to calculate the sum of all root-to-leaf numbers.
     * @param node The current node
     * @param pathSum The sum of root-to-current node path
     * @return The sum of all root-to-leaf numbers
     */
    int dfs(TreeNode* node, int pathSum) {
        if (!node)
            return 0;

        pathSum = pathSum * 10 + node->val;
        if (!node->left && !node->right)
            return pathSum;

        return dfs(node->left, pathSum) + dfs(node->right, pathSum);
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution solution;
    int sum = solution.sumNumbers(root);
    std::cout << "Sum of all root-to-leaf numbers: " << sum << std::endl;
    return 0;
}
