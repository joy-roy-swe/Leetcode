#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    // Function to calculate the maximum depth of parentheses in a string
    int maxDepth(string s) {
        int counter = 0; // Counter to keep track of open parentheses
        int max_depth = INT_MIN; // Variable to store the maximum depth found
        for(char ch : s) {
            if(ch == '(')
                counter++; // Increment counter for an open parenthesis
            else if(ch == ')')
                counter--; // Decrement counter for a closing parenthesis

            max_depth = max(max_depth, counter); // Update the maximum depth
        }
        return max_depth; // Return the maximum depth
    }
};

int main() {
    Solution solution;
    string s = "(a(b)c(d)e)";
    cout << "Maximum depth of parentheses: " << solution.maxDepth(s) << endl;
    return 0;
}
