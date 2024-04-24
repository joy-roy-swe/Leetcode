#include <iostream>

class Solution {
public:
    /**
     * Calculate the nth Tribonacci number.
     * @param n The index of the Tribonacci number to be calculated
     * @return The nth Tribonacci number
     */
    int tribonacci(int n) {
        if(n==0) return 0; // Base case: T(0) = 0
        int left = 0; // Initialize the first Tribonacci number T(0)
        int middle = 1; // Initialize the second Tribonacci number T(1)
        int right = 1; // Initialize the third Tribonacci number T(2)
        int it = 3; // Start the iterator from the fourth Tribonacci number T(3)
        // Calculate the Tribonacci numbers iteratively
        while(it<=n){
            int next=left+middle+right; // Calculate the next Tribonacci number
            left = middle; // Update the left value to the previous middle value
            middle = right; // Update the middle value to the previous right value
            right = next; // Update the right value to the next Tribonacci number
            it++; // Increment the iterator
        }
        return right; // Return the nth Tribonacci number
    }
};

int main() {
    // Example usage
    Solution solution;
    int n = 5;
    int result = solution.tribonacci(n);
    std::cout << "The " << n << "th Tribonacci number is: " << result << std::endl;
    return 0;
}
