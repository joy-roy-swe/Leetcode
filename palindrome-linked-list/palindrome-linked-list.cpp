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

// Some Brute Force Steps to follow
// 1) Reverse the list and store it in r_head;
// and then compare head->val and r_head->val if equal move both the pointers otherwise if not equal return false.
// When the loop will be executed fully retrun true
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // If the linked list is empty or has only one node, it is a palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Initialize a reversed linked list (r_head) and a pointer (ptr)
        ListNode *r_head = NULL;
        ListNode *ptr = head;

        // Reverse the original linked list and store it in r_head
        while (ptr != NULL) {
            // Create a new node with the same value as the current node
            ListNode *temp = new ListNode(ptr->val);

            // Link the new node to the reversed list
            temp->next = r_head;
            r_head = temp;

            // Move to the next node in the original list
            ptr = ptr->next;
        }

        // Compare the original and reversed linked lists for palindrome check
        while (head && r_head) {
            // If values are not equal, the linked list is not a palindrome
            if (head->val != r_head->val) {
                return false;
            }

            // Move to the next nodes in both the original and reversed lists
            head = head->next;
            r_head = r_head->next;
        }

        // If all comparisons are successful, the linked list is a palindrome
        return true;
    }
};