# Problem: Maximum Beauty for Each Query

You are given a 2D integer array `items` where each element `items[i] = [price_i, beauty_i]` denotes the **price** and **beauty** of an item, respectively. You are also given a 0-indexed integer array `queries`. For each `queries[j]`, the goal is to determine the maximum beauty of an item whose price is less than or equal to `queries[j]`. If no such item exists, the answer for that query should be `0`.

Return an array `answer` where `answer[j]` is the maximum beauty for `queries[j]`.

## Examples

### Example 1
**Input:**  
`items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]`

**Output:**  
`[2,4,5,5,6,6]`

**Explanation:**
1. For `queries[0] = 1`, the only item with `price <= 1` is `[1,2]`, so the answer is `2`.
2. For `queries[1] = 2`, items `[1,2]` and `[2,4]` are considered, with max beauty `4`.
3. For `queries[2] = 3` and `queries[3] = 4`, items `[1,2], [3,2], [2,4], [3,5]` are considered, with max beauty `5`.
4. For `queries[4] = 5` and `queries[5] = 6`, all items are considered, and max beauty is `6`.

### Example 2
**Input:**  
`items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]`

**Output:**  
`[4]`

**Explanation:**  
All items have `price = 1`, so the item with the maximum beauty `4` is selected.

### Example 3
**Input:**  
`items = [[10,1000]], queries = [5]`

**Output:**  
`[0]`

**Explanation:**  
No item has `price <= 5`, so the answer is `0`.

## Constraints

- `1 <= items.length, queries.length <= 10^5`
- `items[i].length == 2`
- `1 <= price_i, beauty_i, queries[j] <= 10^9`
