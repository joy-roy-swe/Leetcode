#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initialize adjacency list for the graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1); // Default unidirectional road
        }

        vector<int> answer;

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new road to the graph
            graph[u].push_back(v);

            // Compute the shortest path from 0 to n-1 using BFS
            answer.push_back(bfsShortestPath(graph, n));
        }

        return answer;
    }

private:
    int bfsShortestPath(const vector<vector<int>>& graph, int n) {
        vector<int> distance(n, INT_MAX);
        queue<int> q;

        // Start BFS from city 0
        q.push(0);
        distance[0] = 0;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (int neighbor : graph[city]) {
                if (distance[city] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[city] + 1;
                    q.push(neighbor);
                }
            }
        }

        // Return the shortest path distance to city n-1
        return distance[n - 1];
    }
};
