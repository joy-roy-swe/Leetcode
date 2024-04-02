#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string s, string t) {
        // If the lengths of the two strings are different, they can't be isomorphic
        if(s.size() != t.size())
            return false;

        vector<int> indexS(200, 0); // Stores index of characters in string s
        vector<int> indexT(200, 0); // Stores index of characters in string t

        for(int i = 0; i < s.size(); i++) { // Iterate through each character of the strings
            if(indexS[s[i]] != indexT[t[i]]) { // Check if the index of the current character in string s is different from the index of the corresponding character in string t
                return false; // If different, strings are not isomorphic
            }
            // updating position of current character
            indexS[s[i]] = i + 1; 
            indexT[t[i]] = i + 1;
        }
        // If the loop completes without returning false, strings are isomorphic
        return true;
    }
};

int main() {
    // Example usage
    Solution solution;
    string s = "egg";
    string t = "add";
    cout << "Isomorphic: " << boolalpha << solution.isIsomorphic(s, t) << endl;

    return 0;
}
