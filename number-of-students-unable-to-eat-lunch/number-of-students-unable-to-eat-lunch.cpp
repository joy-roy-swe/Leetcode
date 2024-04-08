#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to count the number of students who will eat their preferred sandwiches
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros = 0; // Count of students preferring sandwich type 0
        int ones = 0; // Count of students preferring sandwich type 1

        // Count the number of students preferring each type of sandwich
        for (int student : students) {
            if (student == 0)
                zeros++; // Increment count if student prefers sandwich type 0
            else
                ones++; // Increment count if student prefers sandwich type 1
        }

        // Iterate through sandwiches and count students who will eat their preferred sandwich
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (zeros == 0)
                    return ones; // If no students prefer sandwich type 0, return count of students preferring type 1
                zeros--; // Decrement count for sandwich type 0 as student takes sandwich
            } else {
                if (ones == 0)
                    return zeros; // If no students prefer sandwich type 1, return count of students preferring type 0
                ones--; // Decrement count for sandwich type 1 as student takes sandwich
            }
        }
        return 0; // All students got their preferred sandwiches
    }
};

int main() {
    Solution solution;
    vector<int> students = {1,1,1,0,0,1}; // Example student preferences
    vector<int> sandwiches = {1,0,0,0,1,1}; // Example sandwich distribution
    cout << "Number of students who will eat their preferred sandwiches: " << solution.countStudents(students, sandwiches) << endl;
    return 0;
}
