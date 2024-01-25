#include<vector>
#include<queue>
#include<iostream>

using namespace std;


//Definition for a binary tree node.
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
    // Function to calculate the average values of each level in a binary tree
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;  // Vector to store the average values of each level
        queue<TreeNode*> q;     // Queue for level-order traversal
        
        // Add the root to the queue for the initial level
        q.push(root);
        
        // Perform level-order traversal
        while (!q.empty()) {
            int N = q.size();  // Number of nodes at the current level
            double sum = 0;    // Sum of values at the current level
            
            // Process all nodes at the current level
            for (int i = 0; i < N; ++i) {
                TreeNode* node = q.front();  // Get the front node from the queue
                q.pop();  // Remove the front node
                
                sum += node->val;  // Add the value of the current node to the sum
                
                // Enqueue the left and right children if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Calculate the average value for the current level and add to the result vector
            result.push_back(sum / N);
        }
        
        return result;
    }
};
