#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        // Iterate through each cell of the board
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word)) // If DFS returns true, the word is found
                    return true;
            }
        }
        return false; // If no match found, return false
    }

    // DFS algorithm to search for the word
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        // If the word is empty, all characters are found, return true
        if (!word.size())
            return true;
        // If the current cell is out of bounds or doesn't match the current character of the word, return false
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
            return false;
        char c = board[i][j]; // Save the current character
        board[i][j] = '*'; // Mark the current cell as visited
        string s = word.substr(1); // Remove the first character from the word
        // Recursively search in all four directions
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        board[i][j] = c; // Restore the original character
        return ret; // Return the result of the search
    }
};

int main() {
    // Example usage
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    string word = "ABCCED";
    Solution solution;
    cout << "Word exists: " << boolalpha << solution.exist(board, word) << endl;

    return 0;
}
