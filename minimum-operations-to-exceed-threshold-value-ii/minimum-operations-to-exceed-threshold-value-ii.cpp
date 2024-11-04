#include <iostream>
#include <vector>
#include <queue> // For priority_queue
#include <functional> // For greater<>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    // Function to find the minimum operations needed
    int minOperations(vector<int>& nums, int k) {
        // Create a min-heap priority queue using the elements of nums
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int operations = 0; // Initialize operation counter
        
        // Continue loop until the top element of the priority queue is greater than or equal to k
        while(pq.top() < k && !pq.empty()) {
            long long x = pq.top(); // Get the smallest element
            pq.pop(); // Remove the smallest element
            long long y = pq.top(); // Get the next smallest element
            pq.pop(); // Remove the next smallest element
            pq.push(2 * x + y); // Push the new element (sum of two smallest elements multiplied by 2)
            operations++; // Increment the operation counter
        }
        
        return operations; // Return the total operations
    }
};

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    Solution solution;
    int result = solution.minOperations(nums, k);

    cout << "Minimum operations needed: " << result << endl;

    return 0;
}
