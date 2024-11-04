#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Sort the tokens in ascending order
        sort(tokens.begin(), tokens.end());

        // Initialize left and right pointers
        int left = 0;
        int right = tokens.size() - 1;

        // Initialize score and maxScore
        int score = 0;
        int maxScore = 0;

        // Greedy approach
        while (left <= right) {
            // If the current token can be used with the available power
            if (tokens[left] <= power) {
                score++; // Increase the score
                power -= tokens[left]; // Decrease the power
                left++; // Move to the next token
                maxScore = max(maxScore, score); // Update maxScore
            }
            // If there are tokens that can be redeemed
            else if (score > 0) {
                score--; // Decrease the score
                power += tokens[right]; // Increase the power by redeeming a token
                right--; // Move to the previous token
            }
            else {
                break; // If no more tokens can be used or redeemed, exit the loop
            }
        }

        return maxScore; // Return the maximum score obtained
    }
};

int main() {
    // Example usage
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    Solution sol;
    cout << "Maximum score: " << sol.bagOfTokensScore(tokens, power) << endl;

    return 0;
}
