#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

class Solution {
public:
    /**
     * Find the minimum height trees in a given graph.
     * @param n The number of nodes in the graph
     * @param edges The list of edges in the graph
     * @return A vector containing the nodes representing the minimum height trees
     */
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> adj; // Adjacency list to store the graph
        // Populate the adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        std::unordered_map<int, int> edge_cnt; // Map to store the count of edges for each node
        std::deque<int> leaves; // Deque to store leaves (nodes with only one neighbor)
        // Initialize edge counts and leaves
        for (const auto& [src, neighbors] : adj) {
            if (neighbors.size() == 1) {
                leaves.push_back(src); // If a node has only one neighbor, it's a leaf
            }
            edge_cnt[src] = neighbors.size(); // Store the count of edges for each node
        }

        // Perform BFS to find minimum height trees
        while (!leaves.empty()) {
            if (n <= 2) { // If there are only two or fewer nodes left, return the remaining nodes as minimum height trees
                return {begin(leaves), end(leaves)};
            }
            int size = leaves.size();
            for (int i = 0; i < size; ++i) {
                int node = leaves.front(); // Get the front node from the deque
                leaves.pop_front(); // Remove the front node from the deque
                --n; // Decrement the total number of nodes
                // Update edge counts for neighbors of the current node
                for (int nei : adj[node]) {
                    --edge_cnt[nei];
                    if (edge_cnt[nei] == 1) { // If a neighbor becomes a leaf after decrementing edge count, add it to the deque
                        leaves.push_back(nei);
                    }
                }
            }
        }

        return {0}; // Return an empty vector if no minimum height trees are found
    }
};

int main() {
    // Example usage
    Solution solution;
    int n = 4;
    std::vector<std::vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    std::vector<int> result = solution.findMinHeightTrees(n, edges);
    std::cout << "Minimum height trees: ";
    for (int node : result) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}
