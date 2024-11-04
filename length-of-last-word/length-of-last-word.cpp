#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to find the length of the last word in a string
    int lengthOfLastWord(string s) {
        int counter = 0; // Initialize a counter for the length of the last word

        // Iterate over the string in reverse order
        for (int idx = s.size() - 1; idx >= 0; --idx) {
            // If characters other than space are encountered after the last word
            if (counter > 0 && s[idx] == ' ')
                return counter; // Return the length of the last word

            // If spaces are encountered at the end of the string or after the last word
            else if (s[idx] == ' ')
                continue; // Skip spaces

            counter++; // Increment the counter for non-space characters
        }

        return counter; // Return the length of the last word
    }
};

int main() {
    // Example usage
    Solution solution;
    string s = "Hello World ";
    cout << "Length of the last word: " << solution.lengthOfLastWord(s) << endl;

    return 0;
}
