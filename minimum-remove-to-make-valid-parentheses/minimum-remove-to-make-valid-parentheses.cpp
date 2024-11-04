#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to remove minimum number of parentheses to make the input string valid
    string minRemoveToMakeValid(string s) {
        int counter = 0; // Counter to keep track of the number of opening parentheses
        
        // First pass: Scan from left to right
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                counter++; // Increment the counter for opening parentheses
            } else if (s[i] == ')') {
                if (counter > 0) {
                    counter--; // Decrement the counter for closing parentheses
                } else {
                    s[i] = '*'; // Mark the invalid closing parentheses
                }
            }
        }

        counter = 0; // Reset the counter
        
        // Second pass: Scan from right to left
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                counter++; // Increment the counter for closing parentheses
            } else if (s[i] == '(') {
                if (counter > 0) {
                    counter--; // Decrement the counter for opening parentheses
                } else {
                    s[i] = '*'; // Mark the invalid opening parentheses
                }
            }
        }

        string result;
        // Construct the result string excluding the marked parentheses
        for (char ch : s) {
            if (ch != '*') {
                result += ch;
            }
        }
        return result; // Return the final valid string
    }
};

int main() {
    Solution solution;
    string input = "(a(b(c)d)"; // Example input string
    cout << "Minimum valid string: " << solution.minRemoveToMakeValid(input) << endl;
    return 0;
}
