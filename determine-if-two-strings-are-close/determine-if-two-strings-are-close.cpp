#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;

        // Arrays to store the frequency of each character in each word
        vector<int> freq1(26, 0), freq2(26, 0);

        // Iterate through the characters of the words
        for (int idx = 0; idx < word1.size(); ++idx) {
            // Count the frequency of each character in the words
            freq1[word1[idx] - 'a']++;
            freq2[word2[idx] - 'a']++;
        }

        // Check if the frequencies are equivalent
        for (int i = 0; i < 26; ++i) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0))
                return false;
        }

        // Sort the frequency arrays to check for equivalent frequencies
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Check if the sorted frequency arrays are equal
        return freq1 == freq2;
    }
};
