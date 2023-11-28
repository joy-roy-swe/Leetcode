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
    int maxDepth(TreeNode* root) {
        // Check if the tree is empty (root is NULL)
        if(root == NULL)
        return 0;
    
        // Initialize a variable to store the maximum depth
        int res = 0;
        // Create a queue for level-order traversal starting from the root
        queue<TreeNode *> q;
        q.push(root);
        // Perform level-order traversal using a while loop
        while(!q.empty()){
            // Increment the depth for each level
            ++ res;
            // Process nodes at the current level
            for(int i = 0, n = q.size(); i < n; ++ i){
                // Retrieve the front node from the queue
                TreeNode *p = q.front();
                q.pop();
                
                // Enqueue the left child if it exists
                if(p -> left != NULL)
                    q.push(p -> left);
                
                // Enqueue the right child if it exists
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }
        // Return the maximum depth of the tree
        return res;
    }
};