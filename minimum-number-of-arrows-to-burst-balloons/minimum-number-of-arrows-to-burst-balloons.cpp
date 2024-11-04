#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the points based on the starting positions
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        int answer = 1;
        int prev_end = points[0][1];

        // Iterate through the sorted points
        for (int idx = 1; idx < points.size(); ++idx) {
            // If the current balloon's start position is beyond the previous end position,
            // it requires a new arrow
            if (prev_end < points[idx][0]) {
                ++answer;
                prev_end = points[idx][1]; // Update the end position
            } else {
                // If the current balloon is within the range of the previous balloon,
                // update the previous end position to the minimum of both ends
                prev_end = min(prev_end, points[idx][1]);
            }
        }
        return answer;
    }
};

int main() {
    Solution obj;

    // Example usage
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int minArrows = obj.findMinArrowShots(points);

    // Print the minimum number of arrows required
    cout << "Minimum number of arrows required: " << minArrows << endl;

    return 0;
}
