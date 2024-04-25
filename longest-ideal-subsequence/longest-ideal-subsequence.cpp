#include <iostream>

class Solution {
public:
    /**
     * Find the length of the longest ideal string in the given string.
     * @param s The input string
     * @param k The tolerance value for character comparison
     * @return The length of the longest ideal string
     */
    int longestIdealString(std::string s, int k) {
        int dp[150] = {}; // Initialize an array to store the dynamic programming values
        int res = 0; // Initialize a variable to store the result
        // Iterate through each character in the string
        for (auto& i : s) {
            // Iterate through characters within the tolerance range of the current character
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = std::max(dp[i], dp[j]); // Update the dynamic programming value for the current character
            res = std::max(res, ++dp[i]); // Update the result with the maximum dynamic programming value
        }
        return res; // Return the length of the longest ideal string
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string s = "example";
    int k = 1;
    int result = solution.longestIdealString(s, k);
    std::cout << "The length of the longest ideal string is: " << result << std::endl;
    return 0;
}
