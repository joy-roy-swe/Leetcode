#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<unordered_map<int, double>> graph(n); // Adjacency list to represent the graph
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            graph[u][v] = p;
            graph[v][u] = p; // Undirected graph
        }

        vector<double> dist(n, 0.0); // Maximum probability of success to reach each node
        dist[start_node] = 1.0; // Probability of reaching the start node is 1

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node}); // Push the start node with probability 1

        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();

            if (u == end_node) {
                return p; // If reached the end node, return the maximum probability of success
            }

            for (auto& [v, p_uv] : graph[u]) {
                double new_p = p * p_uv; // Probability of reaching v from u
                if (new_p > dist[v]) {
                    dist[v] = new_p; // Update the maximum probability of reaching v
                    pq.push({new_p, v});
                }
            }
        }

        return 0.0; // If end node is not reachable, return 0
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {2, 4}, {3, 4}};
    vector<double> succProb = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
    int start_node = 0;
    int end_node = 4;
    double max_prob = sol.maxProbability(n, edges, succProb, start_node, end_node);
    cout << "Maximum probability of success: " << max_prob << endl;

    return 0;
}
