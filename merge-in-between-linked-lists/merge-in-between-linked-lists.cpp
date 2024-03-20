#include <iostream>
#include <vector>

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
    vector<int> templist;
    vector<int> templist2;
    
    // Helper function to convert linked list to vector
    void linkedListToVect(ListNode* list1) {
        ListNode* curr = list1;
        while (curr != nullptr) {
            templist.emplace_back(curr->val);
            curr = curr->next;
        }
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Convert list1 to vector
        linkedListToVect(list1);
        int size = templist.size();
        int idx;
        
        // Copy elements from list1 to templist2 before index 'a'
        for (idx = 0; idx < a; ++idx) {
            templist2.emplace_back(templist[idx]);
        }

        // Append elements from list2 to templist2
        ListNode* curr = list2;
        while (curr != nullptr) {
            templist2.emplace_back(curr->val);
            curr = curr->next;
        }

        // Copy elements from list1 to templist2 after index 'b'
        for (idx = b + 1; idx < size; ++idx) {
            templist2.emplace_back(templist[idx]);
        }

        // Create a new linked list from templist2
        ListNode* dummy = new ListNode(0); // Dummy head
        ListNode* tail = dummy;
        for (int val : templist2) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next; // Return the head of the merged list
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
