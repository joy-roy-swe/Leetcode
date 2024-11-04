#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0; // If the tree is empty, return 0

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            // Check if the current node has a left child and the left child is a leaf node
            if (currNode->left && currNode->left->left == nullptr && currNode->left->right == nullptr) {
                sum += currNode->left->val; // Add the value of the left leaf to the sum
            }

            // Enqueue the left and right children if they exist
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
        }

        return sum;
    }
};

int main() {
    // Example usage of the Solution class
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Sum of left leaves: " << sol.sumOfLeftLeaves(root) << endl;

    // Free memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
