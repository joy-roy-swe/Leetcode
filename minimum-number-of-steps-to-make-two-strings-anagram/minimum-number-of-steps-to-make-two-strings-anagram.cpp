#include <unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    // Function to calculate the minimum number of steps to make two strings 's' and 't' anagrams
    // Input: two strings 's' and 't'
    // Output: the minimum number of steps to make 's' and 't' anagrams
    int minSteps(string s, string t) {
        // Map to store the frequency of each character in string 's'
        unordered_map<char, int> map;
        
        // Variable to store the count of steps needed to make 's' and 't' anagrams
        int count = 0;
        
        // Count the frequency of each character in string 's'
        for (auto ch : s) {
            map[ch]++;
        }
        
        // Iterate through string 't'
        for (auto ch : t) {
            // Check if the character is not present in the frequency map
            if (map.find(ch) == map.end()) {
                // Increment the count as the character is not in 's'
                count++;
            } else {
                // Decrement the frequency in the map and remove the entry if the frequency becomes zero
                map[ch]--;
                if (map[ch] == 0) {
                    map.erase(ch);
                }
            }
        }
        
        // Return the total count of steps needed to make 's' and 't' anagrams
        return count;
    }
};
