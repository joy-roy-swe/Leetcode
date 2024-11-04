/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Check if the linked list is empty, indicating no cycle
        if (head == NULL)
            return false;

        // Initialize two pointers, fast and slow, both initially pointing to the head
        ListNode *fast = head;
        ListNode *slow = head;

        // Traverse the linked list with two pointers to detect a cycle
        while (fast != NULL && fast->next != NULL) {
            // Move the fast pointer two steps at a time
            fast = fast->next->next;

            // Move the slow pointer one step at a time
            slow = slow->next;

            // If there's a cycle (fast and slow pointers meet), return true
            if (fast == slow)
                return true;
        }

        // If the loop completes without detecting a cycle, return false
        return false;
    }
};