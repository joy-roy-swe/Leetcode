#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to check if the given string is a valid string
    bool checkValidString(string s) {
        int counterMin = 0; // Counter for minimum number of open parentheses
        int counterMax = 0; // Counter for maximum number of open parentheses
        for (char ch : s) {
            if (ch == '(') {
                counterMin++; // Increment the counters for open parentheses
                counterMax++;
            } else if (ch == ')') {
                counterMin--; // Decrement the counters for close parentheses
                counterMax--;
            } else {
                counterMin--; // Treat '*' as close parentheses
                counterMax++; // Treat '*' as open parentheses
            }
            if (counterMax < 0) return false; // If max counter is negative, it means too many close parentheses
            if (counterMin < 0) counterMin = 0; // Reset min counter if it goes negative
        }
        return counterMin == 0; // Check if all open parentheses are closed
    }
};

int main() {
    Solution solution;
    string input = "(*()"; // Example input string
    cout << "Is the string valid? " << (solution.checkValidString(input) ? "Yes" : "No") << endl;
    return 0;
}
