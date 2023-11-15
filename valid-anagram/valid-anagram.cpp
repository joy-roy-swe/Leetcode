class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char, int> hash_map;
        for(int i=0; i<s.size(); i++){
            hash_map[s[i]]++;
        }
        for(int j=0; j<t.size(); j++){
            hash_map[t[j]]--;
        }
        for(auto x: hash_map){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};