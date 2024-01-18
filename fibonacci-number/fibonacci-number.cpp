class Solution {
public:
    int fib(int n) {
        int prevFib = 0;    // Variable to store the Fibonacci number for the (n-2)th position
        int currentFib = 1; // Variable to store the Fibonacci number for the (n-1)th position
        int temp = 0;       // Temporary variable used during the iteration
        // Base case: if n is 0, return the 0th Fibonacci number
        if(n==0) return prevFib;
        // Iterate through Fibonacci sequence starting from the third position up to the target position (n)
        for (int i = 2; i <= n; ++i) {
            // Store the value of the current Fibonacci number (currentFib + prevFib) in the temporary variable
            temp = currentFib;
            
            // Update the value for the current Fibonacci number to be the sum of the numbers from the two previous positions
            currentFib = currentFib + prevFib;
            
            // Update the value for the previous Fibonacci number to be the temporary variable (Fibonacci number of the previous position)
            prevFib = temp;
        }
        
        // Return the Fibonacci number for the target position (n)
        return currentFib;
    }
};
