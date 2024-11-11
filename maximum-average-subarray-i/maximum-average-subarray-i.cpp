#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        int windowStart = 0;
        double sum = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) {
            sum += nums[windowEnd];

            // Once we have a window of size k
            if (windowEnd - windowStart == k - 1) {
                maxAvg = max(maxAvg, sum / k);  // Calculate and update max average
                sum -= nums[windowStart++];     // Slide the window by removing the start element
            }
        }
        return maxAvg;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // Find maximum average of subarrays of length k
    double result = solution.findMaxAverage(nums, k);

    cout << "The maximum average of subarrays of length " << k << " is: " << result << endl;

    return 0;
}
