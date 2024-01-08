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
     * Function to swap pairs of nodes in a linked list.
     *
     * Parameters:
     *   - head: The head of the linked list.
     *
     * Return:
     *   - The head of the modified linked list after swapping pairs of nodes.
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();  // Create a dummy node to simplify edge cases
        dummy->next = head;  // Set dummy's next to the head of the original list
        ListNode* node = dummy;  // Initialize a pointer to the dummy node

        while (node != NULL) {
            ListNode* first = node->next;  // Pointer to the first node in the current pair
            ListNode* second = NULL;  // Pointer to the second node in the current pair

            if (first != NULL) {
                second = first->next;  // If the first node exists, set 'second' to its next node
            }

            if (second != NULL) {
                ListNode* secondNext = second->next;  // Save the next node after the pair
                second->next = first;  // Swap the nodes in the pair
                node->next = second;  // Update the pointer from the previous pair to the new second node
                first->next = secondNext;  // Connect the rest of the list to the newly swapped pair
                node = first;  // Move the pointer to the last node in the swapped pair
            } else {
                break;  // If 'second' is NULL, there are no more pairs to swap, exit the loop
            }
        }

        return dummy->next;  // Return the head of the modified linked list
    }
};
