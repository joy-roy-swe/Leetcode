#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    /**
     * Function to reveal cards in increasing order
     * @param deck A vector representing the original deck of cards
     * @return A vector representing the revealed cards in increasing order
     */
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        // Sort the deck in ascending order
        std::sort(deck.begin(), deck.end());
        // Create a vector to store the revealed cards
        std::vector<int> res(deck.size(), 0);
        // Create a deque to simulate the revealing process
        std::deque<int> q;
        // Initialize the deque with indices of the cards
        for (int i = 0; i < deck.size(); ++i) {
            q.push_back(i);
        }
        // Iterate through the sorted deck
        for (int n : deck) {
            // Get the index of the card to reveal
            int i = q.front();
            q.pop_front();
            // Store the revealed card at its corresponding index
            res[i] = n;
            // If there are more cards to reveal
            if (!q.empty()) {
                // Move the next card to the end of the deque
                q.push_back(q.front());
                q.pop_front();
            }
        }
        // Return the vector of revealed cards
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    // Reveal the cards in increasing order
    std::vector<int> result = solution.deckRevealedIncreasing(deck);
    // Print the revealed cards
    for (int card : result) {
        std::cout << card << " ";
    }
    std::cout << std::endl;
    return 0;
}
