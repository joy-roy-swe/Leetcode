#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    vector<int> list;                   // Dynamic array to store the elements
    unordered_map<int, int> map;        // Hash map to store the indices of elements in the array

    RandomizedSet() {
        // Constructor: Initializes an empty set
    }

    // Function to check if a given value exists in the set
    // Input: an integer value 'val'
    // Output: true if 'val' exists in the set, false otherwise
    bool search(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        return true;
    }

    // Function to insert a value into the set
    // Input: an integer value 'val'
    // Output: true if 'val' is successfully inserted, false if 'val' already exists in the set
    bool insert(int val) {
        if (search(val)) {
            return false;
        }
        list.emplace_back(val);                // Insert 'val' at the end of the array
        map[val] = list.size() - 1;            // Update the index of 'val' in the hash map
        return true;
    }

    // Function to remove a value from the set
    // Input: an integer value 'val'
    // Output: true if 'val' is successfully removed, false if 'val' does not exist in the set
    bool remove(int val) {
        if (!search(val)) {
            return false;
        }
        auto it = map.find(val);               // Find the index of 'val' in the hash map
        list[it->second] = list.back();       // Replace 'val' with the last element in the array
        list.pop_back();                      // Remove the last element
        map[list[it->second]] = it->second;   // Update the index of the moved element in the hash map
        map.erase(val);                       // Remove 'val' from the hash map
        return true;
    }

    // Function to retrieve a random element from the set
    // Output: a random integer value from the set
    int getRandom() {
        return list[rand() % list.size()];   // Generate a random index and return the corresponding element
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */