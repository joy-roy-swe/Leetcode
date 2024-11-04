#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Compare two version numbers represented as strings.
     * @param version1 The first version number string
     * @param version2 The second version number string
     * @return -1 if version1 is lower than version2,
     *          0 if version1 is equal to version2,
     *          1 if version1 is higher than version2
     */
    int compareVersion(string version1, string version2) {
        // Split the version strings into tokens based on the '.' delimiter
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        // Initialize indices for iterating through the tokens
        int i = 0, j = 0;
        // Compare corresponding tokens until the end of either version string is reached
        while (i < v1.size() && j < v2.size()) {
            // Convert tokens to integers for comparison
            if (stoi(v1[i]) > stoi(v2[j])) {
                return 1;
            } else if (stoi(v1[i]) < stoi(v2[j])) {
                return -1;
            }
            // Move to the next token
            i++;
            j++;
        }
        // If any tokens remain in version1, check if they are non-zero
        while (i < v1.size()) {
            if (stoi(v1[i]) > 0) {
                return 1;
            }
            i++;
        }
        // If any tokens remain in version2, check if they are non-zero
        while (j < v2.size()) {
            if (stoi(v2[j]) > 0) {
                return -1;
            }
            j++;
        }
        // If both version strings are identical, return 0
        return 0;
    }

private:
    /**
     * Split a string into tokens based on the given delimiter.
     * @param s The input string
     * @param delimiter The character delimiter
     * @return A vector of tokens
     */
    vector<string> split(string s, char delimiter) {
        // Initialize an empty vector to store tokens
        vector<string> tokens;
        // Initialize an empty string to accumulate characters for each token
        string token;
        // Iterate through each character in the input string
        for (char c : s) {
            // If the current character matches the delimiter
            if (c == delimiter) {
                // Add the accumulated token to the vector
                tokens.push_back(token);
                // Clear the token for the next one
                token.clear();
            } else {
                // Append the character to the current token
                token += c;
            }
        }
        // Add the last token to the vector
        tokens.push_back(token);
        return tokens;
    }
};

int main() {
    // Example usage
    Solution solution;
    string version1 = "1.2.3";
    string version2 = "1.2.3";
    int result = solution.compareVersion(version1, version2);
    // Output: 0
    return 0;
}
