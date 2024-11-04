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
        // Step 1: Convert the linked list values to a vector for easy swapping.
        vector<int> tempVec;
        ListNode* current = head;

        // Traverse the linked list and store values in the vector.
        while(current != NULL){
            tempVec.push_back(current->val);
            current = current->next;
        }

        // Determine the size of the vector.
        int size = tempVec.size();

        // Swap the values at positions k-1 and (size-k).
        int temp = tempVec[k-1];
        tempVec[k-1] = tempVec[size-k];
        tempVec[size-k] = temp;

        // Step 2: Create a new linked list with the swapped values.
        ListNode* new_list = new ListNode(0);
        ListNode* currentNewList = new_list;

        // Populate the new linked list with the swapped values.
        for(int element : tempVec){
            currentNewList->next = new ListNode(element);
            currentNewList = currentNewList->next;
        }

        // Return the head of the new linked list (skipping the dummy head).
        return new_list->next;
    }
};