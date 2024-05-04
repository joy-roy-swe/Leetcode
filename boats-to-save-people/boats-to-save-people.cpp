#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Calculate the minimum number of rescue boats required to save all people.
     * @param people The weights of people
     * @param limit The maximum weight limit of each boat
     * @return The minimum number of rescue boats required
     */
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people in non-decreasing order of weights
        sort(people.begin(), people.end());
        // Initialize variables for counting rescue boats and iterating through people
        int counter = 0;
        int left = 0;
        int right = people.size() - 1;
        
        // Iterate through the people from both ends
        while (left <= right) {
            // If the weights of the lightest and heaviest people can fit into one boat
            if (people[left] + people[right] <= limit) {
                left++; // Move to the next lightest person
            }
            right--; // Move to the next heaviest person
            counter++; // Increment the count of rescue boats used
        }
        
        return counter; // Return the total count of rescue boats
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    int result = solution.numRescueBoats(people, limit);
    // Output: 3
    return 0;
}
