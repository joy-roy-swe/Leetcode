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
    void reorderList(ListNode* head) {
        if (!head || !head->next) // Check if the list is empty or has only one node
            return;

        // Store the values of the list in a vector
        vector<int> list;
        ListNode* current = head;
        while (current) {
            list.emplace_back(current->val);
            current = current->next;
        }

        // Reorder the list values
        vector<int> answer;
        int left = 0;
        int right = list.size() - 1;
        int counter = 0;

        while (left <= right) {
            if (counter % 2 == 0) {
                answer.emplace_back(list[left]);
                left++;
            } else {
                answer.emplace_back(list[right]);
                right--;
            }
            counter++;
        }

        // Construct the reordered list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int num : answer) {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
        head->next = dummy->next->next; // Update the original list
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    solution.reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
