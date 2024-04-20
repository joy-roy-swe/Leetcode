#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool inBound(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        vector<vector<int>> answer;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (visited[row][col] || land[row][col] == 0) continue;
                queue<pair<int, int>> q;
                visited[row][col] = 1;
                q.push({row, col});
                int l = row, r = col; // Initialize l and r here
                while (!q.empty()) {
                    auto current = q.front();
                    q.pop(); // Pop the front element
                    int a = current.first, b = current.second;
                    for (int i = 0; i < 4; ++i) {
                        int x = a + dx[i], y = b + dy[i];
                        if (inBound(x, y, n, m) && visited[x][y] == 0 && land[x][y] == 1) {
                            visited[x][y] = 1;
                            q.push({x, y});
                            l = max(l, x); // Update leftmost column
                            r = max(r, y); // Update rightmost column
                        }
                    }
                }
                answer.push_back({row, col, l, r});
            }
        }
        return answer;
    }
};
