vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    /**
     * @brief Calculates the difference between the count of ones and zeros in rows and columns of a binary matrix.
     *
     * Given a binary matrix 'grid', this function computes the difference between the count of ones and zeros in each row and column.
     * The result is a new matrix where each element (i, j) represents the difference in count for the corresponding row and column.
     *
     * @param grid Binary matrix to process.
     * @return A new matrix representing the difference between ones and zeros in rows and columns.
     */
    // Get matrix sizes
    int m = grid.size(), n = grid[0].size();

    // Initialize vectors to store counts for each row and column
    vector<int> row0(m), row1(m), col0(n), col1(n);

    // Calculate counts for each row
    int r0, r1;
    for(int i=0; i<m; ++i){
        r0 = r1 = 0;
        for(int j=0; j<n; ++j){
            if(grid[i][j] == 0)
                r0++;
            else
                r1++;
        }
        row0[i] = r0;
        row1[i] = r1;
    }

    // Calculate counts for each column
    int c0, c1;
    for(int j=0; j<n; ++j){
        c0 = c1 = 0;
        for(int i=0; i<m; ++i){
            if(grid[i][j] == 0)
                c0++;
            else
                c1++;
        }
        col0[j] = c0;
        col1[j] = c1;
    }

    // Create a new matrix to store the differences between ones and zeros in rows and columns
    vector<vector<int>> diff(m, vector<int>(n, 0));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            // Calculate the difference for each element (i, j)
            diff[i][j] = row1[i] + col1[j] - row0[i] - col0[j];
        }
    }

    return diff;
}
