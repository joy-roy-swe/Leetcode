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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Check if the tree is empty
        if (root == NULL)
            return {};

        // Initialize a vector to store the final result
        vector<vector<int>> ans;

        // Initialize a vector to store the values of nodes at each level
        vector<int> v;

        // Variables for tracking the number of nodes at the current level (n) and a queue for level-order traversal
        int n;
        queue<TreeNode*> q;

        // Pointer for traversing the tree
        TreeNode* p;

        // Enqueue the root of the tree to start the level-order traversal
        q.push(root);

        // Perform level-order traversal using a while loop
        while (!q.empty()) {
            // Get the number of nodes at the current level
            n = q.size();

            // Clear the vector to store values for the current level
            v.clear();

            // Process nodes at the current level
            while (n--) {
                // Dequeue a node from the front of the queue
                p = q.front();
                q.pop();

                // Add the value of the dequeued node to the vector for the current level
                v.push_back(p->val);

                // Enqueue the left and right children if they exist
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }

            // Add the vector containing values of the current level to the final result vector
            ans.push_back(v);
        }

        // Return the final result
        return ans;
    }

};