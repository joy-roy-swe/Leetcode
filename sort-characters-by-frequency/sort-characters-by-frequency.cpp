#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Vector to store character counts, initialized with 128 pairs
        // Each pair represents a character (ASCII value) and its frequency
        vector<pair<char, int>> counts(128, {0, 0});
        
        // Count frequencies of characters
        for(char ch : s){
            counts[ch].first = ch; // Store the character
            counts[ch].second++;   // Increment the frequency count
        }
        
        // Sort the vector based on frequency in descending order
        sort(counts.begin(), counts.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Sort by frequency in descending order
        });
        
        string str;
        // Append characters to the result string based on sorted frequency
        for(auto& entry: counts) {
            for(int i = 0; i < entry.second; ++i) {
                str += entry.first;
            }
        }
        return str;
    }
};

int main() {
    // Example usage of Solution class
    string input = "tree";
    Solution sol;
    string sortedString = sol.frequencySort(input);
    cout << "Input string: " << input << endl;
    cout << "Sorted string by frequency: " << sortedString << endl;
    return 0;
}
