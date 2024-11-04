#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Iterate until left pointer reaches right pointer or characters at both pointers are equal
        while (left != right && s[left] == s[right]) {
            char ch = s[left];

            // Move left pointer to the right while characters match
            while (left <= right && s[left] == ch)
                ++left;

            // Move right pointer to the left while characters match
            while (left < right && s[right] == ch)
                --right;
        }
        // Return the length of the remaining substring
        return right - left + 1;
    }
};

int main() {
    // Example usage
    Solution sol;
    string s = "caaccbbc";
    cout << "Minimum length of non-palindromic substring: " << sol.minimumLength(s) << endl;

    return 0;
}
