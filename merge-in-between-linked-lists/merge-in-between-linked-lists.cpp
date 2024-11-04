#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Initialize a counter to keep track of the position in the list
        int counter = 0;
        // Initialize a pointer 'start' to traverse to the node just before index 'a'
        ListNode* start = list1;
        // Move 'start' pointer to the node just before index 'a'
        while (counter < a - 1) {
            start = start->next;
            counter++;
        }
        // Initialize a pointer 'end' to traverse to the node at index 'b'
        ListNode* end = start;
        // Move 'end' pointer to the node at index 'b'
        while (counter <= b) {
            end = end->next;
            counter++;
        }
        // Connect the node before 'a' to the head of list2
        start->next = list2;
        // Traverse to the end of list2
        while (list2->next) {
            list2 = list2->next;
        }
        // Connect the end of list2 to the node at index 'b' (end)
        list2->next = end;
        // Return the modified list1
        return list1;
    }
};

int main() {
    // Example usage
    Solution obj;

    // Creating linked list 1: 0->1->2->3->4->5
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    // Creating linked list 2: 100->101->102
    ListNode* list2 = new ListNode(100);
    list2->next = new ListNode(101);
    list2->next->next = new ListNode(102);

    int a = 2; // Index a
    int b = 4; // Index b

    // Merging list2 between indices a and b of list1
    ListNode* mergedList = obj.mergeInBetween(list1, a, b, list2);

    // Print the merged list
    ListNode* curr = mergedList;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
