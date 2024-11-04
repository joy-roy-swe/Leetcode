#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int size = s.size();
        int half = size / 2;
        int count = 0;

        // Create an unordered_set to store vowels
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        // Iterate through the string
        for (int i = 0; i < size; ++i) {
            // Check if the current character is a vowel using vowels.count()
            if (vowels.count(s[i]) && i < half) {
                // Increment count if the vowel is in the first half
                count++;
            } else if (vowels.count(s[i]) && i >= half) {
                // Decrement count if the vowel is in the second half
                count--;
            }
        }
        // If count is 0, both halves have an equal number of vowels
        return count == 0;
    }
};
