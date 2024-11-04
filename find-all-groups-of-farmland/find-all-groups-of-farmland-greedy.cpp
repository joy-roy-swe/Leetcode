#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        int n = land.size(), m = land[0].size();
        vector<vector<int>> answer;

        for(int row1=0; row1<n; ++row1){
            for(int col1=0; col1<m; ++col1){
                if(land[row1][col1]){
                    int row2 = row1, col2 = col1;
                    for(row2=row1; row2<n && land[row2][col1]; ++row2){
                        for(col2=col1; col2<m && land[row2][col2]; ++col2){
                            land[row2][col2]=0;
                        }
                    }
                    answer.push_back({row1, col1, row2, col2});
                }
            }
        }
        return answer;
    }
};