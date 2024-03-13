#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    // Function to find the pivot integer for a given number
    int pivotInteger(int n) {
        // Calculate the pivot using the formula: sqrt(n * (n + 1) / 2)
        double pivot = sqrt(n * (n + 1) / 2);
        // Check if the pivot is an integer
        return pivot - ceil(pivot) == 0 ? (int)pivot : -1;
    }
};

int main() {
    // Example usage of the pivotInteger function
    Solution sol;

    // Test the function with different values of n
    for (int n = 1; n <= 10; ++n) {
        int result = sol.pivotInteger(n);
        cout << "Pivot integer for n = " << n << " is: " << result << endl;
    }

    return 0;
}
