from typing import List
from bisect import bisect_right

class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        # Step 1: Sort items by the first value (beauty).
        items.sort(key=lambda x: x[0])
        
        # Step 2: Precompute the prefix maximum beauty values.
        prefix_max = []
        max_beauty = 0
        for item in items:
            max_beauty = max(max_beauty, item[1])
            prefix_max.append(max_beauty)
        
        # Step 3: For each query, use binary search to find the rightmost item.
        answer = []
        for query in queries:
            # bisect_right finds the index where the query could be inserted.
            idx = bisect_right(items, [query, float('inf')]) - 1
            
            # If idx is -1, no items satisfy the condition
            if idx == -1:
                answer.append(0)
            else:
                answer.append(prefix_max[idx])
        
        return answer
         
    
def main():
    items = [[1,2],[3,2],[2,4],[5,6],[3,5]]
    queries = [1,2,3,4,5,6]
    soltion = Solution()
    result = soltion.maximumBeauty(items, queries)
    print(result)

if __name__ == "__main__":
    main()