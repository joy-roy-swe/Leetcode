class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // Brute Force Solution
        bool find = true;
        int special = 0;
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[0].size(); ++j){
                // If the element is 0, continue to the next iteration
                if(mat[i][j] == 0)
                    continue;
                // Flag to determine if the element is "special"
                find = true;
                // Checking the entire column for other '1's except for the current row
                for(int row=0; row<mat.size(); ++row){
                    if(row!=i && mat[row][j]==1){
                        // If a '1' is found in the same column in another row, mark as not "special"
                        find = false; 
                        break;
                    }
                }
                // Checking the entire row for other '1's except for the current column
                for(int col=0; col<mat[0].size(); ++col){
                    if(col!=j && mat[i][col]==1){
                        // If a '1' is found in the same row in another column, mark as not "special"
                        find = false; 
                        break;
                    }
                }
                // If the element is "special," increment the count
                if(find) 
                    special++;
            } 
        }
        // Return the count of "special" elements
        return special;
    }
};