/**
 * @file string-compression-iii.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 * leetcode 1531: String Compression III
 */

/*
*   Solution Steps: two pointer solution
    
    1. Initialize Two Pointers:
        -windowStart starts at index 0.
        -windowEnd starts at index 1.
    2. Iterate Through the String:
        -Use a while loop that continues as long as windowStart is less than the length of the string word.

    3. Identify Character Sequence:
        - For each unique character sequence starting from windowStart, count the consecutive repetitions of 
        this character up to a maximum of 9 characters:

            - Set count to 0.
            - Use an inner loop where windowEnd moves forward until:
                - It either encounters a different character than word[windowStart],
                - Or it reaches the end of the string,
                - Or it reaches a count of 9.
    4. Add the Sequence to Result (comp):
        - Append count and the character at windowStart to comp.
        - Example: If there are 9 consecutive 'a' characters, it would append "9a" to comp.
    5. Move windowStart Forward:
        - Set windowStart to the position of windowEnd after counting the sequence.
        - windowEnd will automatically start counting from the new position on the next iteration.
    6. Return the Result:
        - After the loop completes, return the comp string as the compressed result.
*/




#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    string compressedString(string word){
        if (word.empty()) 
            return "";
        
        string comp = "";
        int n = word.size();
        int windowStart = 0;

        while (windowStart < n) {
            char currentChar = word[windowStart];
            int count = 0;

            // Count the number of consecutive currentChar characters, up to a max of 9
            while (windowStart + count < n && word[windowStart + count] == currentChar && count < 9) {
                count++;
            }

            // Append the count and character to the compressed result
            comp += to_string(count) + currentChar;

            // Move the windowStart forward by the count we just processed
            windowStart += count;
        }

        return comp;
    }
};

