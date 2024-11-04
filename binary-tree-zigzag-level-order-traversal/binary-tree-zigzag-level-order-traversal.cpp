#include<vector>
#include<queue>
#include<iostream>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};  // Return an empty vector if the tree is empty
        vector<vector<int>> answer;  // Vector to store the result
        queue<TreeNode*> q;  // Queue for level-order traversal
        int levelCount = 0;  // Counter to track the level
        
        // Add the root to the queue for the initial level
        q.push(root);
        
        // Perform level-order traversal
        while(!q.empty()) {
            vector<int> level;  // Vector to store values at the current level
            int N = q.size();   // Number of nodes at the current level
            ++levelCount;       // Increment the level counter
            
            // Process all nodes at the current level
            for(int i = 0; i < N; ++i) {
                TreeNode* node = q.front();  // Get the front node from the queue
                q.pop();  // Remove the front node
                
                level.push_back(node->val);  // Add the value of the current node to the level vector
                
                // Enqueue the left and right children if they exist
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            // Reverse the level vector if the current level is even (zigzag pattern)
            if(levelCount % 2 == 0)
                reverse(level.begin(), level.end());
            
            answer.push_back(level);  // Add the level vector to the result vector
        }
        
        return answer;
    }
};
