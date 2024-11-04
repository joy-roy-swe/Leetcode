#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    /**
     * Find the last non-empty string with the maximum occurrence of characters.
     * @param s The input string
     * @return The last non-empty string with maximum occurrence of characters
     */
    std::string lastNonEmptyString(std::string s) {
        std::unordered_map<char, int> map; // Map to count occurrences of each character
        int maxOccurrence = 0; // Initialize the maximum occurrence count

        // Count occurrences of each character in the string
        for (char c : s) {
            map[c]++;
            maxOccurrence = std::max(maxOccurrence, map[c]); // Update the maximum occurrence count
        }

        std::string answer = ""; // Initialize the answer string
        std::unordered_set<char> unique; // Set to store unique characters encountered while traversing the string

        // Traverse the string from right to left to find the last non-empty string with maximum occurrence
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i]; // Current character
            // If the current character has maximum occurrence and is not already added to the answer
            if (map[c] == maxOccurrence && unique.find(c) == unique.end()) {
                answer = c + answer; // Prepend the character to maintain order
                unique.insert(c); // Add the character to the set of unique characters
            }
        }

        return answer; // Return the last non-empty string with maximum occurrence of characters
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string input = "aabbcdd";
    std::cout << "Last non-empty string with maximum occurrence: " << solution.lastNonEmptyString(input) << std::endl;
    return 0;
}
