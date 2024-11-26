#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  // Create a set called numbers that will store integers
  set<int> numbers;
  
  vector<vector<int>> edges = {{0, 1}, {1, 2}};
  
  for (const auto& edge : edges) {
    numbers.insert(edge[1]);
  }

  // Find the unique element, if any
  int answer = -1; // Default to -1
  int count = 0;

  for (int i = 0; i < 3; ++i) {
    if (numbers.find(i) != numbers.end()) {
      count++;
      answer = i;
    }
  }

  if (count == 1) {
    return answer; // Return the unique number
  }
  return -1; // Return -1 if no unique number exists
}
