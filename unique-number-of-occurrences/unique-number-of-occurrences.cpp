#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        // Create an unordered map to store the frequency of each element in the array.
        std::unordered_map<int, int> map;
        
        // Create an unordered set to store the unique frequencies.
        std::unordered_set<int> unique;
        
        // Iterate through the array to calculate the frequency of each element.
        for (auto it : arr) {
            map[it]++;
        }
        
        // Iterate through the frequency map to insert the frequencies into the unique set.
        for (auto it : map) {
            unique.insert(it.second);
        }
        
        // Check if the number of unique frequencies is equal to the total number of elements in the array.
        return map.size() == unique.size();
    }
};
