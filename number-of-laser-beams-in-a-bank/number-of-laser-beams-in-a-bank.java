class Solution {
    public int numberOfBeams(String[] bank) {
        int prevRowCount = 0;
        int total = 0;
        for(String row: bank){
            int currentRowCount = getRowCount(row);
            if(currentRowCount == 0)
                continue;
            total += prevRowCount * currentRowCount;
            prevRowCount = currentRowCount;
        }
        return total;
    }
    private int getRowCount(String row){
        int count = 0;
        for(char ch: row.toCharArray()){
            count += ch - '0';
        }
        return count;
    }
}