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
    /*
     * Approach:
     *
     * Initialize 'head' and 'tail' pointers to nullptr for the resulting linked list.
     * Use 'carry' to handle digit addition that exceeds 9.
     * Traverse both input linked lists (l1 and l2) and add corresponding digits along with the carry.
     * Create a new node with the sum % 10.
     * Update 'tail' to point to the new node, and if 'head' is nullptr, set 'head' to the new node.
     * Move to the next nodes if available.
     * Continue the process until both input linked lists are exhausted, and there is no remaining carry.
     * Return the resulting linked list.
     */

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;  // Initialize 'head' to nullptr
        ListNode* tail = nullptr;  // Initialize 'tail' to nullptr
        int carry = 0;

        while (l1 || l2 || carry) {
            // Calculate the sum of corresponding digits along with the carry
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;

            // Create a new node with the sum % 10
            ListNode* newNode = new ListNode(sum % 10);

            if (!head) {
                // If 'head' is nullptr, set both 'head' and 'tail' to the new node
                head = newNode;
                tail = newNode;
            } else {
                // Update 'tail' to point to the new node
                tail->next = newNode;
                tail = newNode;
            }

            // Move to the next nodes if available
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head;  // Return the resulting linked list
    }
};

