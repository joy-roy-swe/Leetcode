class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Create an unordered set to store all cities that appear as the first element in any pair
        unordered_set<string> sourceCities;

        // Iterate through each path
        for (const auto& path : paths) {
            sourceCities.insert(path[0]);
        }

        // Iterate through each path again and find the destination city
        for (const auto& path : paths) {
            // Check if the second element in the pair is not in the set of source cities
            if (sourceCities.find(path[1]) == sourceCities.end()) {
                return path[1];
            }
        }

        // Return an empty string if no destination city is found (should not happen given the problem constraints)
        return "";
    }
};