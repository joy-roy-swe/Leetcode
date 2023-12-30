class Solution {
public:
    // Function to check if it is possible to distribute characters equally among words
    // Input: vector of strings 'words'
    // Output: true if characters can be distributed equally, false otherwise
    bool makeEqual(vector<string>& words) {
        // If there is only one word, characters are already equal
        if (words.size() == 1) {
            return true;
        }

        // Calculate the total number of characters in all words
        int totalCharCount = 0;
        for (const string& s : words) {
            totalCharCount += s.length();
        }

        // If the total number of characters is not divisible by the number of words,
        // characters cannot be distributed equally
        if (totalCharCount % words.size() != 0) {
            return false;
        }

        // Create a map to store the frequency of each character
        vector<int> myMap(26, 0);
        for (const string& s : words) {
            for (char c : s) {
                myMap[c - 'a']++;
            }
        }

        // Check if the frequency of each character is divisible by the number of words
        for (int i : myMap) {
            if (i % words.size() != 0) {
                return false;
            }
        }

        // Characters can be distributed equally among words
        return true;
    }
};