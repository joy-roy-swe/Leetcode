#include <iostream>
#include <queue>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX

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
    // Function to check if the given binary tree is an even-odd tree
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return true; // Special case: an empty tree is considered even-odd

        queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Level index
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues; // To store values of the current level for validation
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();
                levelValues.push_back(currNode->val);
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }

            // Check the properties based on the level parity
            if (level % 2 == 0) {
                // Even-indexed level: check if all values are odd and in strictly increasing order
                if (!checkIncreasingOdd(levelValues)) return false;
            } else {
                // Odd-indexed level: check if all values are even and in strictly decreasing order
                if (!checkDecreasingEven(levelValues)) return false;
            }
            level++; // Move to the next level
        }
        return true; // Tree satisfies the conditions
    }

    // Function to check if all values in a vector are odd and in strictly increasing order
    bool checkIncreasingOdd(const vector<int>& levelValues) {
        int prevVal = INT_MIN; // To store the previous value for comparison
        for (int val : levelValues) {
            if (val % 2 == 0 || val <= prevVal) return false;
            prevVal = val;
        }
        return true;
    }

    // Function to check if all values in a vector are even and in strictly decreasing order
    bool checkDecreasingEven(const vector<int>& levelValues) {
        int prevVal = INT_MAX; // To store the previous value for comparison
        for (int val : levelValues) {
            if (val % 2 != 0 || val >= prevVal) return false;
            prevVal = val;
        }
        return true;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(12);

    Solution solution;
    bool result = solution.isEvenOddTree(root);

    cout << "Is the given binary tree an even-odd tree? " << (result ? "Yes" : "No") << endl;

    return 0;
}
