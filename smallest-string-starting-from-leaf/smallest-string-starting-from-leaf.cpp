#include <iostream>
#include <string>

using namespace std;

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
     * Find the smallest string representation from the leaf to root in a binary tree.
     * @param root The root of the binary tree
     * @return The smallest string representation
     */
    string smallestFromLeaf(TreeNode* root) {
        string small_string = ""; // Initialize an empty string to store the smallest string
        dfs(root, "", small_string); // Call the depth-first search helper function
        return small_string; // Return the smallest string found
    }

    /**
     * Perform depth-first search to traverse the binary tree and find the smallest string representation.
     * @param node The current node in the binary tree
     * @param path The string representing the path from the root to the current node
     * @param small_string The smallest string found so far
     */
    void dfs(TreeNode* node, string path, string& small_string) {
        // Base case: If the current node is null, return
        if (!node)
            return;

        // Append the character representing the current node's value to the path string
        path += char('a' + node->val);

        // If the current node is a leaf node, check if the path string is smaller than the smallest string found so far
        if (!node->left && !node->right) {
            // Reverse the path string to get the string representation from leaf to root
            reverse(path.begin(), path.end());
            // If the smallest string found so far is empty or the current path string is smaller, update the smallest string
            if (small_string.empty() || path < small_string) {
                small_string = path;
            }
            // Reverse the path string back to its original order
            reverse(path.begin(), path.end());
        }

        // Recursively call dfs function for left and right subtrees
        dfs(node->left, path, small_string);
        dfs(node->right, path, small_string);
    }
};

int main() {
    // Example usage
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    std::cout << "Smallest string from leaf to root: " << solution.smallestFromLeaf(root) << std::endl;
    return 0;
}
