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

/*
* Take two pointers fist and slow at the head of linked list.
* Move fast pointers by n to the right. Here n = 2.
* Then move both fast and slow pointers to right until fast reaches the end.
* Then change pointer of slow node to its next to next node.
* Delete the last nth node (optional).
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return head;
    }
};