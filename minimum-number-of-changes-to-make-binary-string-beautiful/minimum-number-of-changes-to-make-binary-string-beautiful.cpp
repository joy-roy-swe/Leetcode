/**
 * @file minimum-number-of-changes-to-make-binary-string-beautiful.cpp
 * @author joy.roy
 * @brief 
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 * leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i+=2){
            if(s[i]!=s[i+1]) count++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    string s = "010101"; // Example input
    cout << "Minimum changes to make the string beautiful: " << solution.minChanges(s) << endl;
    return 0;
}