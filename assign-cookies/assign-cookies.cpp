class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int childIndex = 0, cookieIndex = 0;
        int count = 0;
        while(childIndex < g.size() && cookieIndex < s.size()){
            if(s[cookieIndex] >= g[childIndex]){
                count++;
                childIndex++;
            }
            cookieIndex++;
        }
        return count;
    }
};