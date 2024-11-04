#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to remove zero-sum sublists from a linked list
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
            return head; // Return null if the head is null

        ListNode* current = head;
        int sum = 0;

        // Traverse the linked list
        while (current != nullptr) {
            sum += current->val; // Update the sum
            if (sum == 0) {
                head = current->next; // Remove the current node if sum becomes zero
                // delete current; // Optional: Free the memory of the removed node
                return removeZeroSumSublists(head); // Recursively remove zero-sum sublists
            }
            current = current->next;
        }

        // Recursively remove zero-sum sublists from the next nodes
        head->next = removeZeroSumSublists(head->next);
        return head; // Return the modified head
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage of removeZeroSumSublists function
    Solution sol;

    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    cout << "Original linked list: ";
    printLinkedList(head);

    // Remove zero-sum sublists
    head = sol.removeZeroSumSublists(head);

    cout << "Linked list after removing zero-sum sublists: ";
    printLinkedList(head);

    return 0;
}
