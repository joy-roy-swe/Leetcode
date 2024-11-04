#include<iostream>
#include<vector>
#include<queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> answer;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int N = q.size();
            for(int i=0; i<N; ++i){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            answer.push_back(level);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};