#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
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
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int maxLength = 0; // Initialize the maximum length of the diameter
        getDiameter(root, maxLength); // Calculate the diameter recursively
        return maxLength; // Return the maximum length of the diameter
    }
    
    // Recursive function to calculate the diameter and update the maximum length
    int getDiameter(TreeNode* currNode, int& answer) {
        if (!currNode) return 0; // Base case: If the current node is null, return 0
        int left = getDiameter(currNode->left, answer); // Recursively calculate the diameter of the left subtree
        int right = getDiameter(currNode->right, answer); // Recursively calculate the diameter of the right subtree
        answer = max(answer, left + right); // Update the maximum length if necessary
        return max(left, right) + 1; // Return the maximum depth of the current subtree
    }
};

int main() {
    // Create nodes for a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance of the Solution class
    Solution solution;

    // Find the diameter of the binary tree
    int result = solution.diameterOfBinaryTree(root);

    // Output the result
    cout << "Diameter of the Binary Tree: " << result << endl;

    return 0;
}
