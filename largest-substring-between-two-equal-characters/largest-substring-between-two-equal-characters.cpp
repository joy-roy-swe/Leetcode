class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_length = -1;
        for(int i=0; i<s.size(); ++i){
            for(int j=i+1; j<s.size(); ++j){
                if(s[i]==s[j]){
                    max_length = max(max_length, j-i-1);
                }
            }
        } 
        return max_length;
    }
};