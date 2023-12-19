class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Get image size
        int m = img.size();
        int n = img[0].size();

        // Initialize a result vector
        vector<vector<int>> result(m, vector<int>(n,0));

        // Define direction for the surrouding cells
        int dirs[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        // Iterate directions for the surrounding cells
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                int sum = 0;
                int count = 0;

                // Iterate through each of the surrouding cells
                for(int k=0; k<9; ++k){
                    int ni = i+dirs[k][0];
                    int nj = j+dirs[k][1];

                    // Check if the surrouding cell is within the bounds of the matrix
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                        sum += img[ni][nj];
                        ++count;
                    }
                }
                // Calculate the average and assign it to the corresponding cell in result matrix
                result[i][j] = sum/count;
            }
        }
        return result;
    }
};