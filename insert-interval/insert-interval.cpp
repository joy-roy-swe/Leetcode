#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;

        // Add all intervals before newInterval
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged interval
        res.push_back(newInterval);

        // Add remaining intervals after newInterval
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main() {
    Solution obj;

    // Example usage
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = obj.insert(intervals, newInterval);

    // Print the result
    cout << "Merged Intervals:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
