#include <iostream>
#include <string>
#include <algorithm> // For count()

using namespace std;

class Solution {
public:
    // Function to return the maximum odd binary number
    string maximumOddBinaryNumber(string s) {
        int n = s.size(); // Length of the input string
        int n1 = count(s.begin(), s.end(), '1'); // Count of '1's in the string
        int n0 = n - n1; // Count of '0's in the string

        // Form the maximum odd binary number
        return string(n1 - 1, '1') + string(n0, '0') + string(1, '1');
    }
};

int main() {
    // Example usage
    string s = "110";
    Solution solution;
    string result = solution.maximumOddBinaryNumber(s);

    cout << "Maximum odd binary number: " << result << endl;

    return 0;
}
