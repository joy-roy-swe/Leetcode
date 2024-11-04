#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    // Function to find winners in a list of matches
    // Input: vector of matches, where each match is represented as a vector of two integers
    // Output: vector containing two sub-vectors - 
    //         1. All winners who have not lost any match
    //         2. Losers who have lost exactly one match
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Map to store the count of losses for each player
        unordered_map<int, int> lose_map;

        // Count the number of losses for each player
        for (auto& match : matches) {
            int loser = match[1];
            lose_map[loser]++;
        }

        // Vectors to store the results
        vector<int> all_win, once_lose;

        // Iterate through the matches to find winners and losers
        for (auto& match : matches) {
            int winner = match[0];
            int loser = match[1];

            // Check if the winner has not lost any match
            if (lose_map.find(winner) == lose_map.end()) {
                all_win.emplace_back(winner);
                lose_map[winner] = 2;  // Mark as a player who has not lost any match
            }

            // Check if the loser has lost exactly one match
            if (lose_map[loser] == 1) {
                once_lose.emplace_back(loser);
            }
        }

        // Sort the results vectors
        sort(all_win.begin(), all_win.end());
        sort(once_lose.begin(), once_lose.end());

        // Return the result as a vector of two sub-vectors
        return {all_win, once_lose};
    }
};
