#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>>graph;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        unordered_set<int> visited;

        q.push(source);
        visited.insert(source);

        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current==destination) return true;

            for(int neighbor :graph[current]){
                if(visited.find(neighbor)==visited.end()){
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};