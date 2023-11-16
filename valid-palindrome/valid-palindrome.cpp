class Solution {
public:
    bool isPalindrome(string s) {
        // Initiaze two pointer
        int left = 0, right=s.size()-1;
        // converting all uppercase letters into lowercase letters
        for(int idx=0; idx<s.size(); ++idx){
            s[idx]=tolower(s[idx]);
        }
        // check all word to check palindrome or not
        while(left<=right){
            // removing all non-alphanumeric characters from start
            if(!(s[left]>='a' && s[left]<='z') && !(s[left]>='0' && s[left]<='9')){
                ++left;
            }
            // removing all non-alphanumeric characters from end
            else if(!(s[right]>='a' && s[right]<='z') && !(s[right]>='0' && s[right]<='9')){
                --right;
            }
            else if(s[left]==s[right]){
                ++left; --right;
            }
            else 
                return false;
        }
        return true;
        
    }
};