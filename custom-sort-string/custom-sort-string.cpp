#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    // Function to custom sort the string 's' based on the order given in 'order'
    string customSortString(string order, string s) {
        unordered_map<char, int> map; // Map to store the frequency of characters in 's'
        string answer = ""; // Initialize the answer string

        // Count the frequency of each character in 's'
        for (char ch : s) {
            map[ch]++;
        }

        // Traverse the order string and append characters in the order specified
        for (char ch : order) {
            // Append characters from 's' if they exist in the order string
            while (map[ch] > 0) {
                answer += ch;
                map[ch]--;
            }
            // Remove the character from the map after appending
            map.erase(ch);
        }

        // Append the remaining characters from 's' that are not in the order string
        for (auto ch : map) {
            while (ch.second != 0) {
                answer += ch.first;
                ch.second--;
            }
        }

        // Return the custom sorted string
        return answer;
    }
};

int main() {
    // Example usage of customSortString function
    Solution sol;
    string order = "cba";
    string s = "abcd";
    cout << "Custom sorted string: " << sol.customSortString(order, s) << endl;
    return 0;
}
