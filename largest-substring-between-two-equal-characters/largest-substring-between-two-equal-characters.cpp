class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // Variable to store the maximum distance between equal characters
        int max_length = -1;
        
        // Map to store the last index where each character was encountered
        unordered_map<char, int> characters;
        
        // Iterate through the string
        for (int i = 0; i < s.size(); ++i) {
            // Check if the current character has been encountered before
            if (characters.find(s[i]) != characters.end()) {
                // Calculate the distance between the current index and the last index of the character
                max_length = max(max_length, i - characters[s[i]] - 1);
            } else {
                // Update the map with the current character and its index
                characters[s[i]] = i;
            }
        }
        
        // Return the maximum distance between equal characters
        return max_length;
    }
};
