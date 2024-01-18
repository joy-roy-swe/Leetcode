class Solution {
public:
    int climbStairs(int n) {
        // Initialize variables to store the number of ways for the current step, the previous step, and a temporary variable
        int one = 1; // Represents the number of ways to climb 1 step
        int two = 1; // Represents the number of ways to climb 2 steps
        int temp = 0; // Temporary variable used during the iteration
        
        // Iterate through the steps starting from the third step up to the target step
        for (int i = 2; i <= n; i++) {
            // Store the value of the current step (one + two) in the temporary variable
            temp = one;
            
            // Update the value for the current step to be the sum of the ways of the previous two steps
            one = one + two;
            
            // Update the value for the previous step to be the temporary variable (ways of the previous step)
            two = temp;
        }
        
        // Return the number of ways to climb the given number of steps
        return one;
    }
};
