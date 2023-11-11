class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checkrow[10][10]={0}, checkcol[10][10]={0}, checkbox[10][10]={0};
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                // skip empty cells
                if(board[row][col]=='.') 
                    continue;
                //as 'char' is given we make it int
                int num = board[row][col]-'0';
                // get the sub-box
                int box = (row/3)*3+(col/3);
                // check if num has already been seen in the same row or column or 3x3 sub-box
                if(checkrow[row][num] || checkcol[col][num] || checkbox[box][num]) 
                    return false;
                checkrow[row][num]=checkcol[col][num]=checkbox[box][num]=true;
            }
        }
        return true;
    }
};