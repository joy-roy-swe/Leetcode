#include <unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int charCount[26] = {0}; // Array to store the frequency of each character ('a' to 'z')
        int count = 0;

        // Count the frequency of each character in string 's'
        for (char ch : s) {
            charCount[ch - 'a']++;
        }

        // Iterate through string 't'
        for (char ch : t) {
            // Check if the character is not present in the frequency array
            if (charCount[ch - 'a'] == 0) {
                // Increment the count as the character is not in 's'
                count++;
            } else {
                // Decrement the frequency in the array
                charCount[ch - 'a']--;
            }
        }

        // Return the total count of steps needed to make 's' and 't' anagrams
        return count;
    }
};
