#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can_distribute(int x, const vector<int>& quantities, int n) {
    int stores_needed = 0;
    for (int quantity : quantities) {
        stores_needed += (quantity + x - 1) / x;  // Equivalent to ceil(quantity / x)
        if (stores_needed > n) return false;  // More stores than available
    }
    return stores_needed <= n;
}

int minMaximumProducts(int n, vector<int>& quantities) {
    int start = 1, end = *max_element(quantities.begin(), quantities.end());
    int best_x = end;

    // Perform binary search
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (can_distribute(mid, quantities, n)) {
            best_x = mid;  // If possible, try a smaller value of x
            end = mid - 1;
        } else {
            start = mid + 1;  // If not possible, try a larger value of x
        }
    }

    return best_x;
}

int main() {
    cout << minMaximumProducts(6, {11, 6}) << endl;  // Output: 3
    cout << minMaximumProducts(7, {15, 10, 10}) << endl;  // Output: 5
    cout << minMaximumProducts(1, {100000}) << endl;  // Output: 100000
    return 0;
}
