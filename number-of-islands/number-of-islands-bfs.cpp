#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    /**
     * Function to perform depth-first search (DFS) to mark an island as visited.
     * @param grid: The grid representing the map of '1's (land) and '0's (water).
     * @param M: Number of rows in the grid.
     * @param N: Number of columns in the grid.
     * @param row: Current row index.
     * @param col: Current column index.
     */
    void findingIsland(vector<vector<char>>& grid, int M, int N, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});

        // Iterate while the queue is not empty
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int currentRow = it.first;
            int currentCol = it.second;

            // Check boundary conditions and if the current cell is land ('1')
            if (currentRow >= M || currentCol >= N || currentRow < 0 || currentCol < 0 || grid[currentRow][currentCol] == '0')
                continue;

            // Mark the current cell as visited
            grid[currentRow][currentCol] = '0';

            // Enqueue neighboring cells
            q.push({currentRow - 1, currentCol});
            q.push({currentRow, currentCol - 1});
            q.push({currentRow + 1, currentCol});
            q.push({currentRow, currentCol + 1});
        }
        return;
    }

    /**
     * Function to count the number of islands in the grid.
     * @param grid: The grid representing the map of '1's (land) and '0's (water).
     * @return The total number of islands.
     */
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        int islandCount = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                // If the cell is land ('1'), mark the island as visited
                if (grid[i][j] == '1') {
                    islandCount++;
                    findingIsland(grid, M, N, i, j);
                }
            }
        }
        return islandCount;
    }
};
