#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    /**
     * Function to solve the 'Surrounded Regions' problem.
     * @param board: The 2D board representing 'X' (blocked) and 'O' (unblocked) cells.
     */
    void solve(vector<vector<char>>& board) {
        int n = board.size(); // Number of rows in the board
        int m = board[0].size(); // Number of columns in the board

        // 2D vector to track visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Queue to perform breadth-first search from boundary cells
        queue<pair<int, int>> q;

        // Enqueue boundary cells with 'O' and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        // Array to represent possible moves: up, right, down, left
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // Perform breadth-first search from boundary cells
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Explore neighboring cells
            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                // Check if the neighboring cell is valid and unvisited
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && board[nr][nc] == 'O') {
                    vis[nr][nc] = 1; // Mark the neighboring cell as visited
                    q.push({nr, nc}); // Enqueue the neighboring cell
                }
            }
        }

        // Process the entire board and mark unvisited 'O' cells as 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
