#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to calculate the time required to buy tickets
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0; // Initialize total time

        // Iterate through each ticket stand
        for (int idx = 0; idx < tickets.size(); ++idx) {
            // If the ticket stand index is less than or equal to the preferred stand index
            if (idx <= k) {
                // If the price of the ticket at the current stand is higher than at the preferred stand
                if (tickets[idx] > tickets[k]) {
                    time += tickets[k]; // Buy ticket from the preferred stand
                } else {
                    time += tickets[idx]; // Buy ticket from the current stand
                }
            } else {
                // If the ticket stand index is greater than the preferred stand index
                // If the price of the ticket at the current stand is higher than or equal to at the preferred stand
                if (tickets[idx] >= tickets[k]) {
                    time += tickets[k] - 1; // Buy ticket from the preferred stand with a discount
                } else {
                    time += tickets[idx]; // Buy ticket from the current stand
                }
            }
        }
        return time; // Return total time required to buy tickets
    }
};

int main() {
    Solution solution;
    vector<int> tickets = {2, 4, 5, 1, 3}; // Prices of tickets at each stand
    int k = 2; // Preferred stand index
    cout << "Time required to buy tickets: " << solution.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}
