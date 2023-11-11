class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int row=0; row<size; ++row){
		    for(int col=0; col<row; ++col){
			    swap(matrix[row][col], matrix[col][row]);
		    }
	    }
	    for(int idx=0; idx<size; ++idx){
		    reverse(matrix[idx].begin(), matrix[idx].end());
	    }
    }
};