#include <iostream>
#include <string>
#include <algorithm> // For max()

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        int charMap[128] = {0}; // Assuming ASCII characters

        for(int end = 0; end < s.length(); end++) {
            // If the character is already seen, update the start index to the next position of the repeated character
            if(charMap[s[end]] > 0) {
                start = max(start, charMap[s[end]]);
            }
            charMap[s[end]] = end + 1; // Update the position of the character in the map
            maxLength = max(maxLength, end - start + 1); // Update the maximum length
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb"; // Example input string
    int result = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}
