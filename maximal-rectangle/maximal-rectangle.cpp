#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    /**
     * Find the area of the largest rectangle containing only 1s in a binary matrix.
     * @param matrix The input binary matrix
     * @return The area of the largest rectangle
     */
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        // Initialize a vector to store the heights of each column in the matrix
        std::vector<int> heights(cols + 1, 0); // Include an extra element for easier calculation
        int maxArea = 0;

        // Iterate through each row in the matrix
        for (const auto& row : matrix) {
            // Update the heights vector based on the current row
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }

            // Calculate max area using stack-based method
            std::stack<int> stk;
            for (int i = 0; i < heights.size(); i++) {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    int w = stk.empty() ? i : i - stk.top() - 1;
                    maxArea = std::max(maxArea, h * w);
                }
                stk.push(i);
            }
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    // Find the area of the largest rectangle containing only 1s in the matrix
    int maxRectangleArea = solution.maximalRectangle(matrix);
    std::cout << "Area of the largest rectangle containing only 1s: " << maxRectangleArea << std::endl;
    return 0;
}
