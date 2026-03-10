# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Edge case: if the input list is empty, return None
        if not lists:
            return None
        
        # Keep merging pairs until only one list remains
        while len(lists) > 1:
            merged = []  # Holds the results of this round
            
            # Step through lists in pairs (0&1, 2&3, 4&5, ...)
            for i in range(0, len(lists), 2):
                l1 = lists[i]
                # If odd number of lists, last one has no pair → set l2 = None
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                # Merge the two lists and store result
                merged.append(self.mergeTwoLists(l1, l2))
            
            # Replace lists with the merged results for next round
            lists = merged
        
        # Only one list left → that's our fully merged answer
        return lists[0]
    
    def mergeTwoLists(self, l1, l2):
        # Dummy node acts as a starting anchor for the result list
        dummy = ListNode(0)
        current = dummy  # Pointer that builds the merged list
        
        # Compare heads of both lists, pick the smaller one
        while l1 and l2:
            if l1.val <= l2.val:
                current.next = l1    # Attach l1's node
                l1 = l1.next         # Move l1 forward
            else:
                current.next = l2    # Attach l2's node
                l2 = l2.next         # Move l2 forward
            current = current.next   # Move current forward
        
        # One list is exhausted → attach the remaining nodes
        current.next = l1 if l1 else l2
        
        # dummy.next is the real head of merged list
        return dummy.next