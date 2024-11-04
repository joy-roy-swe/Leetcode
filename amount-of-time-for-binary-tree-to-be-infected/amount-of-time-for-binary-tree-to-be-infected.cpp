#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

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
    // An unordered map to represent an adjacency list graph for the binary tree nodes.
    unordered_map<int, vector<int>> graph;

    /**
     * Calculate the amount of time it takes for a signal to reach all nodes in a binary tree
     * starting from the specified node.
     *
     * Parameters:
     *   - root: The root of the binary tree.
     *   - start: The node from which the signal starts.
     *
     * Return:
     *   - The amount of time for the signal to reach all nodes.
     */
    int amountOfTime(TreeNode* root, int start) {
        // Construct the adjacency list graph representation for the binary tree.
        constructGraph(root);

        // Initialize a queue for breadth-first traversal starting from the specified node.
        queue<int> q;
        q.push(start);

        // Set to track visited nodes.
        unordered_set<int> visited;

        // Initialize the total time to -1.
        int totalTime = -1;

        // Breadth-first traversal loop.
        while (!q.empty()) {
            ++totalTime;

            // Process nodes at the current level.
            for (int level = q.size(); level > 0; --level) {
                // Retrieve the front node from the queue.
                int currentNode = q.front();
                q.pop();

                // Mark the current node as visited.
                visited.insert(currentNode);

                // Explore adjacent nodes.
                for (int adjacentNode : graph[currentNode]) {
                    // If the adjacent node is not visited, add it to the queue.
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        // Return the total time taken for the signal to reach all nodes.
        return totalTime;
    }

    /**
     * Construct the adjacency list graph representation for the binary tree.
     *
     * Parameters:
     *   - root: The current root of the binary tree.
     */
    void constructGraph(TreeNode* root) {
        // Base case: If the root is null, return.
        if (!root) {
            return;
        }
        // Check if the node is already in the graph before adding edges.
        if (graph.find(root->val) == graph.end()) {
            graph.emplace(root->val, vector<int>());
        }

        // Add edges to the graph for left and right child relationships.
        if (root->left) {
            graph[root->val].emplace_back(root->left->val);
            graph[root->left->val].emplace_back(root->val);
        }

        if (root->right) {
            graph[root->val].emplace_back(root->right->val);
            graph[root->right->val].emplace_back(root->val);
        }

        // Recursively construct the graph for left and right subtrees.
        constructGraph(root->left);
        constructGraph(root->right);
    }
};
