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
    ListNode* oddEvenList(ListNode* head) {
        // Check if the linked list is empty.
        if (!head || !head->next) {
            return head;
        }

        // Initialize pointers for odd and even nodes, and a pointer to the start of the even nodes.
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_start = head->next;

        // Traverse the linked list and rearrange nodes.
        while (odd->next && even->next) {
            // Connect odd node to the next odd node.
            odd->next = even->next;
            
            // Move to the next odd node.
            odd = odd->next;

            // Connect even node to the next even node.
            even->next = odd->next;

            // Move to the next even node.
            even = even->next;
        }

        // Connect the last odd node to the start of the even nodes.
        odd->next = even_start;

        // Return the modified linked list.
        return head;
    }
};