#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Get the number of rows and columns in the matrix
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        // Create vectors to keep track of zero rows and columns
        vector<bool> zeroRow(rowSize, false);
        vector<bool> zeroCol(colSize, false);
        
        // Mark rows and columns containing zeros
        for(int row = 0; row < rowSize; ++row) {
            for(int col = 0; col < colSize; ++col) {
                if(matrix[row][col] == 0) {
                    zeroRow[row] = true;
                    zeroCol[col] = true;
                }
            }
        }
        
        // Zero out rows marked with true in zeroRow
        for(int row = 0; row < rowSize; ++row) {
            if(zeroRow[row]) {
                for(int col = 0; col < colSize; ++col) {
                    matrix[row][col] = 0;
                }
            }
        }

        // Zero out columns marked with true in zeroCol
        for(int col = 0; col < colSize; ++col) {
            if(zeroCol[col]) {
                for(int row = 0; row < rowSize; ++row) {
                    matrix[row][col] = 0;
                }
            }
        }
    }
};

int main() {
    // Example usage of the setZeroes function
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    Solution sol;
    sol.setZeroes(matrix);

    // Print the modified matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
