#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the first palindrome string in a given vector of strings
    string firstPalindrome(vector<string>& words) {
        string answer = ""; // Initialize an empty string to store the result
        bool palindrome = true; // Flag to check if a word is a palindrome
        for(string word : words) { // Iterate through each word in the vector
            palindrome = isPalindrome(word); // Check if the current word is a palindrome
            if(palindrome) { // If the current word is a palindrome
                answer = word; // Update the answer with the palindrome word
                break; // Break the loop since we found the first palindrome
            }  
        }
        return answer; // Return the first palindrome found (empty string if none found)
    }
    
    // Function to check if a string is a palindrome
    bool isPalindrome(string word) {
        int left = 0; // Initialize left pointer
        int right = word.size() - 1; // Initialize right pointer
        while(left < right) { // Loop until left pointer is less than right pointer
            if(word[left] != word[right]) // If characters at left and right pointers are different
                return false; // Not a palindrome, return false
            left++; // Move left pointer to the right
            right--; // Move right pointer to the left
        }
        return true; // If the loop completes, the word is a palindrome, return true
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    vector<string> words = {"level", "hello", "world", "racecar"}; // Example vector of words
    string result = solution.firstPalindrome(words); // Find the first palindrome in the vector
    cout << "First Palindrome: " << result << endl; // Output the result
    return 0;
}
