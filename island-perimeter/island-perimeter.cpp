#include <iostream>
#include <vector>
#include <set>

using namespace std;

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //unordered_set<int> visited;

    int islandPerimeter(vector<vector<int>>& grid) {
        int totalPerimeter = 0;
        for(int row = 0; row < grid.size(); ++row) {
            for(int col = 0; col < grid[0].size(); ++col) {
                if(grid[row][col]) {
                    totalPerimeter += dfs(grid, row, col);
                }
            }
        }
        return totalPerimeter;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == 0) {
            return 1;
        }
        
        if(grid[row][col]==-1) {
            return 0;
        }

        grid[row][col] = -1;

        int perim = dfs(grid, row, col + 1);
        perim += dfs(grid, row + 1, col);
        perim += dfs(grid, row, col - 1);
        perim += dfs(grid, row - 1, col);

        return perim;
    }
};
