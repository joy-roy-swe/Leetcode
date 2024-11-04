#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to group anagrams from a given vector of strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered_map to store groups of anagrams
        unordered_map<string, vector<string>> hashmap;
        // Vector to store the final answer
        vector<vector<string>> answer;

        // Iterate through each string in the input vector
        for (auto i : strs)
        {
            // Create a copy of the string to use as a key
            string key = i;
            // Sort the characters of the key string to identify anagrams
            sort(key.begin(), key.end());
            // Add the original string to the corresponding group in the hashmap
            hashmap[key].push_back(i);
        }

        // Print the contents of the hashmap
        for (auto x : hashmap)
        {
            // Print the key (sorted string) and its corresponding values (anagrams)
            cout << "Key: " << x.first << ", Values: ";
            for (auto val : x.second) {
                cout << val << " ";
            }
            cout << endl;
        }

        // Copy the grouped anagrams from the hashmap to the answer vector
        for (auto x : hashmap)
        {
            answer.push_back(x.second);
        }
        // Return the grouped anagrams
        return answer;
    }
};

// Sample usage of the Solution class
int main() {
    // Sample input vector of strings
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // Create an instance of the Solution class
    Solution sol;
    // Call the groupAnagrams function to group the anagrams in the input vector
    sol.groupAnagrams(strs);
    // Return 0 to indicate successful execution
    return 0;
}
