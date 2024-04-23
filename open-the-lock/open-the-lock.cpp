#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    /**
     * Generate possible children from a lock by rotating each digit.
     * @param lock The current lock combination
     * @return A vector containing the possible children
     */
    std::vector<std::string> children(std::string lock) {
        std::vector<std::string> result; // Vector to store the generated children
        // Iterate over each digit in the lock combination
        for (int it = 0; it < 4; ++it) {
            std::string newLock = lock; // Create a copy of the lock combination
            // Rotate the current digit to the next digit (clockwise)
            newLock[it] = ((lock[it] - '0' + 1) % 10) + '0';
            result.emplace_back(newLock); // Add the new lock combination to the result vector
            // Rotate the current digit to the previous digit (anti-clockwise)
            newLock[it] = ((lock[it] - '0' - 1 + 10) % 10) + '0';
            result.emplace_back(newLock); // Add the new lock combination to the result vector
        }
        return result; // Return the vector containing the generated children
    }

    /**
     * Find the minimum number of turns required to open the lock.
     * @param deadends The list of deadends (combinations that cannot be reached)
     * @param target The target combination to unlock
     * @return The minimum number of turns required to unlock the target combination, or -1 if it is not possible
     */
    int openLock(std::vector<std::string>& deadends, std::string target) {
        // Check if the initial combination "0000" is a deadend
        if (std::find(deadends.begin(), deadends.end(), "0000") != deadends.end())
            return -1; // If it is, return -1 indicating that the lock cannot be opened

        std::unordered_set<std::string> visited(deadends.begin(), deadends.end()); // Set to store visited combinations
        std::queue<std::pair<std::string, int>> q; // Queue for BFS traversal
        q.push({"0000", 0}); // Push the initial combination "0000" with a turn counter of 0

        // Perform BFS traversal until the queue is empty
        while (!q.empty()) {
            auto [lock, counter] = q.front(); // Get the current combination and turn counter from the front of the queue
            q.pop(); // Remove the front element from the queue
            if (lock == target)
                return counter; // If the current combination matches the target, return the turn counter

            // Generate children of the current combination and check if they have been visited
            for (const auto& child : children(lock)) {
                if (!visited.count(child)) {
                    visited.insert(child); // Mark the child as visited
                    q.push({child, counter + 1}); // Push the child and increment the turn counter
                }
            }
        }
        return -1; // If the target combination cannot be reached, return -1
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    std::string target = "0202";
    std::cout << "Minimum number of turns required to open the lock: " << solution.openLock(deadends, target) << std::endl;
    return 0;
}
