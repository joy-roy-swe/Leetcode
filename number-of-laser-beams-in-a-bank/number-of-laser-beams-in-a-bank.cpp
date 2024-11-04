class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCount = 0;
        int total = 0;
        for(string row: bank){
            int currentRowCount = getCount(row);
            if(currentRowCount==0)
                continue;
            total += prevRowCount * currentRowCount;
            prevRowCount = currentRowCount;
        }
        return total;
    }
    int getCount(string row){
        int count = 0;
        for(char ch: row){
            count += ch - '0';
        }
        return count;
    }
};