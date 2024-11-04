#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    // Function to remove adjacent characters of the same type and case
    string makeGood(string s) {
        int fast = 0; // Fast pointer to track the current position
        for(int slow = 0; slow < s.size(); ++slow) {
            if(fast > 0 && abs(s[slow] - s[fast - 1]) == 32) {
                // If the current character and the previous character form a pair, remove them
                fast--;
            } else {
                // Otherwise, keep the current character
                s[fast++] = s[slow];
            }
        }
        return s.substr(0, fast); // Return the substring containing the resulting string
    }
};

int main() {
    Solution solution;
    string input = "leEeetcode"; // Example input string
    cout << "After removing adjacent characters: " << solution.makeGood(input) << endl;
    return 0;
}
