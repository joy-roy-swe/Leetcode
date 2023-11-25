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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Pointers for the merged list
        ListNode *head = nullptr;
        ListNode *ptr = nullptr;
        ListNode *current = nullptr;

        // Temporary vector to store values from both lists
        vector<int> tempList;

        // Traverse the first linked list and add values to tempList
        while(list1){
            tempList.push_back(list1->val);
            list1 = list1->next;
        }

        // Traverse the second linked list and add values to tempList
        while(list2){
            tempList.push_back(list2->val);
            list2 = list2->next;
        }

        // Sort the tempList to get values in ascending order
        sort(tempList.begin(), tempList.end());

        // Reconstruct the merged linked list using sorted values
        for(int i = 0; i < tempList.size(); i++){
            // Create a new node
            ptr = new ListNode();
            ptr->val = tempList[i];

            // If it's the first node, set head and current to it
            if(i == 0){
                head = ptr;
                current = head;
            }
            // If it's not the first node, link it to the current node
            else{
                current->next = ptr;
                current = current->next;
            }
        }

        // Return the head of the merged list
        return head;
    }
};