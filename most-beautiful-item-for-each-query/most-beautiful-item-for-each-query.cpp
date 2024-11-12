#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Step 1: Sort items by the first value (beauty)
        sort(items.begin(), items.end());

        // Step 2: Precompute the prefix maximum beauty values
        int n = items.size();
        vector<int> prefix_max(n);
        prefix_max[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], items[i][1]);
        }

        // Step 3: Process each query using binary search
        vector<int> answer;
        for (int q : queries) {
            // Use binary search to find the largest index where items[i][0] <= q
            // `upper_bound` gives us the first element that is greater than the query
            int idx = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX}) - items.begin() - 1;
            if (idx == -1) {
                answer.push_back(0);  // No valid item found
            } else {
                answer.push_back(prefix_max[idx]);
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> items = {{4, 6}, {7, 5}, {2, 10}, {3, 8}};
    vector<int> queries = {5, 10, 7};
    
    vector<int> result = sol.maximumBeauty(items, queries);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
