class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        // Count operations starting with '0'
        int count_start_with_0 = 0;
        for (int i = 0; i < n; ++i) {
            if ((i % 2 == 0 && s[i] != '0') || (i % 2 == 1 && s[i] != '1')) {
                ++count_start_with_0;
            }
        }

        // Count operations starting with '1'
        int count_start_with_1 = 0;
        for (int i = 0; i < n; ++i) {
            if ((i % 2 == 0 && s[i] != '1') || (i % 2 == 1 && s[i] != '0')) {
                ++count_start_with_1;
            }
        }

        // Choose the minimum count
        return min(count_start_with_0, count_start_with_1);
    }
};