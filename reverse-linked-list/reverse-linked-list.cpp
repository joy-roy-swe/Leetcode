/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;    // Save the next node
            current->next = prev;    // Reverse the link
            prev = current;          // Move prev to the current node
            current = next;          // Move current to the next node
        }
        head = prev;
        return head;
    }
};