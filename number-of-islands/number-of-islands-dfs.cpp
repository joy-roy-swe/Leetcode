#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
     * Perform depth-first search to explore the current island and mark visited cells as '0'.
     * @param grid The grid representing the land and water areas
     * @param row The current row index
     * @param col The current column index
     */
    void dfs(vector<vector<char>>& grid, int row, int col) {
        // Base condition: If the current cell is out of bounds or represents water ('0'), return
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0')
            return;

        // Mark the current cell as visited by changing its value to '0'
        grid[row][col] = '0';

        // Explore adjacent cells in all four directions (up, down, left, right) using depth-first search
        dfs(grid, row + 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row - 1, col);
        dfs(grid, row, col - 1);
    }

    /**
     * Count the number of islands in a given grid.
     * @param grid The grid representing the land and water areas
     * @return The number of islands
     */
    int numIslands(vector<vector<char>>& grid) {
        int island_count = 0; // Initialize the island count
        // Iterate through each cell in the grid
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                // If the current cell represents land ('1'), increment the island count and perform depth-first search
                if (grid[row][col] == '1') {
                    island_count += 1;
                    dfs(grid, row, col); // Call the depth-first search function to explore the island
                }
            }
        }
        return island_count; // Return the total number of islands
    }

};

int main() {
    // Example usage
    Solution solution;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << "Number of islands: " << solution.numIslands(grid) << std::endl;
    return 0;
}
