#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    /**
     * Remove k digits from a given number to form the smallest possible number.
     * @param num The input number as a string
     * @param k The number of digits to remove
     * @return The smallest possible number after removing k digits
     */
    std::string removeKdigits(std::string num, int k) {
        // Create a stack to store digits
        std::stack<char> stack;
        
        // Iterate through each digit in the number
        for (char digit : num) {
            // Remove digits from the stack as long as the current digit is smaller
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            // Push the current digit onto the stack
            stack.push(digit);
        }
        
        // Remove remaining k digits from the end of the stack
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        // Construct the resulting string from the stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        // Reverse the string to get the correct order
        std::reverse(result.begin(), result.end());
        
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        result = (pos == std::string::npos) ? "0" : result.substr(pos);
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string num = "1432219";
    int k = 3;
    // Remove k digits to form the smallest number
    std::string result = solution.removeKdigits(num, k);
    std::cout << "Smallest number after removing " << k << " digits: " << result << std::endl;
    return 0;
}
