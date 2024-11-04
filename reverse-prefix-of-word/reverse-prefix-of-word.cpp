#include <iostream>
#include <algorithm>

class Solution {
public:
    /**
     * Reverse the prefix of a word until a specified character.
     * @param word The input word
     * @param ch The character indicating where to stop reversing
     * @return The word with the prefix reversed until the specified character
     */
    std::string reversePrefix(std::string word, char ch) {
        int it = 0; // Initialize an iterator to traverse the word
        // Iterate through the characters of the word
        for (it = 0; it < word.size(); ++it) {
            if (word[it] == ch) // Check if the current character is the specified character
                break; // If found, break out of the loop
        }
        // If the iterator reached the end of the word without finding the specified character
        if (it == word.size())
            return word; // Return the original word
        // Reverse the prefix of the word until the specified character
        std::reverse(word.begin(), word.begin() + it + 1);
        return word; // Return the modified word
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string word = "example";
    char ch = 'a';
    std::string result = solution.reversePrefix(word, ch);
    std::cout << "The word with the reversed prefix until '" << ch << "' is: " << result << std::endl;
    return 0;
}
