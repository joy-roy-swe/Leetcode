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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize two pointers, ptr1 and ptr2, to the heads of the input linked lists.
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        // Traverse the linked lists until the intersection point is found or both reach the end.
        while(ptr1 != ptr2){
            // If ptr1 reaches the end of list A, reset it to the head of list B.
            if(ptr1 == NULL)
                ptr1 = headB;
            // Move ptr1 to the next node in list A.
            else
                ptr1 = ptr1->next;

            // If ptr2 reaches the end of list B, reset it to the head of list A.
            if(ptr2 == NULL)
                ptr2 = headA;
            // Move ptr2 to the next node in list B.
            else
                ptr2 = ptr2->next;
        }

        // Either ptr1 (intersection point) or nullptr is returned based on whether an intersection was found.
        return ptr1;
    }
};