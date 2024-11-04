#include <iostream>
#include <queue>

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
    // Function to find the leftmost value of the bottom row in a binary tree
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0; // Handle edge case where root is null
        queue<TreeNode*> q;
        q.push(root);
        int lastValue = root->val; // Initialize lastValue with root value
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();
                if (i == 0) lastValue = currNode->val; // Update lastValue at the beginning of each level
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }
        }
        return lastValue;
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Find the leftmost value of the bottom row in the binary tree
    int result = solution.findBottomLeftValue(root);

    // Output the result
    cout << "Leftmost value of the bottom row: " << result << endl;

    return 0;
}
