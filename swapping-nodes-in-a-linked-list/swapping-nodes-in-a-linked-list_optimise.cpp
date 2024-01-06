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
    ListNode* swapNodes(ListNode* head, int k) {
        // Step 1: Count the total number of nodes in the linked list.
        int size = 0;
        ListNode* current = head;
        while(current != NULL){
            size++;
            current = current->next;
        }

        // Step 2: Traverse the linked list to find the kth and (size-k+1)th node
        ListNode* leftKthNode = head;
        ListNode* rightKthNode = head;
        //  Starts at i = 1 to move the kthNode to the kth position in the linked list.
        for(int i=1; i<k; ++i){
            leftKthNode =  leftKthNode->next;
        }
        // Starts at i = 0 to move the endMinusKNode to the (size-k+1)th position in the linked list.
        for(int i=0; i<size-k; ++i){
            rightKthNode = rightKthNode->next;
        }
        
        // Step 3: Swap the value of the kth and (size-k+1)th nodes.
        swap(leftKthNode->val, rightKthNode->val);

        // Return the updated linked list
        return head;
    }
};