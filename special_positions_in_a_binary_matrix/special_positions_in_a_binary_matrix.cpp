class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowCount(m, 0); // Count of '1's in each row
        vector<int> colCount(n, 0); // Count of '1's in each column
        int special = 0;

        // Calculate counts of '1's in each row and each column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowCount[i] += mat[i][j];
                colCount[j] += mat[i][j];
            }
        }

        // Check if each '1' is the only '1' in its row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    special++;
                }
            }
        }

        return special;
    }
};
