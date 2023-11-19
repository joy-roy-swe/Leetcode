class Solution {
public:
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.size();
        int needle_len = needle.size();
        
        if(needle_len==0) return 0;
        
        for(int idx=0; idx<=(haystack_len-needle_len); ++idx){
            if(haystack[idx]==needle[0]){
                int k=1;
                for(; k<needle_len; ++k){
                    if(haystack[idx+k]!=needle[k]) break;
                }
                if(k==needle_len) return idx;
            }
        }
        return -1;
    }
};