# Problem: Shortest Path Length After Each Query

You are given an integer `n` and a 2D integer array `queries` representing a sequence of road additions in a network of cities. The goal is to compute the shortest path from city `0` to city `n - 1` after processing each query.

---

## Problem Statement

- **Input:**
  - An integer `n`: Number of cities (`0` to `n - 1`).
  - A 2D array `queries`: Each query adds a new unidirectional road from `queries[i][0]` to `queries[i][1]`.

- **Initial Setup:**
  - There is already a unidirectional road from city `i` to city `i + 1` for all `0 <= i < n - 1`.

- **Output:**
  - An array `answer` where `answer[i]` is the length of the shortest path from city `0` to city `n - 1` after processing the first `i + 1` queries.

---

## Examples

### Example 1

**Input:**  
`n = 5`, `queries = [[2,4],[0,2],[0,4]]`

**Output:**  
`[3,2,1]`

**Explanation:**  
1. Add road from `2` to `4`. Shortest path from `0` to `4`:  
   Path: `0 -> 1 -> 2 -> 4`. Length = `3`.

2. Add road from `0` to `2`. Shortest path from `0` to `4`:  
   Path: `0 -> 2 -> 4`. Length = `2`.

3. Add road from `0` to `4`. Shortest path from `0` to `4`:  
   Path: `0 -> 4`. Length = `1`.

---

### Example 2

**Input:**  
`n = 4`, `queries = [[0,3],[0,2]]`

**Output:**  
`[1,1]`

**Explanation:**  
1. Add road from `0` to `3`. Shortest path from `0` to `3`:  
   Path: `0 -> 3`. Length = `1`.

2. Add road from `0` to `2`. Shortest path remains the same:  
   Path: `0 -> 3`. Length = `1`.

---

## Constraints

- `3 <= n <= 500`
- `1 <= queries.length <= 500`
- `queries[i].length == 2`
- `0 <= queries[i][0] < queries[i][1] < n`
- `1 < queries[i][1] - queries[i][0]`
- There are no repeated roads in the queries.

---

## Approach

### Step 1: Represent the Graph
- Use an adjacency list to represent the road network.
- Initially, include roads from `i` to `i + 1` for all `0 <= i < n - 1`.

### Step 2: Update Graph for Each Query
- For each query, add the road `queries[i][0] -> queries[i][1]`.

### Step 3: Compute Shortest Path
- Use **Breadth-First Search (BFS)** from city `0` to compute the shortest path to city `n - 1` after processing each query.
- Store the result for each query in the `answer` array.

---

## Algorithm

1. **Initialize Graph:**
   - Build an adjacency list representing the initial roads.

2. **Process Queries:**
   - For each query `queries[i]`:
     - Add the road `queries[i][0] -> queries[i][1]` to the graph.
     - Run BFS to compute the shortest path from `0` to `n - 1`.

3. **Store Results:**
   - Append the shortest path length to the `answer` array.

4. **Return Results:**
   - Return the `answer` array.

---

## Complexity

- **Time Complexity:**  
  - BFS: `O(V + E)` for each query, where:
    - `V = n` (number of cities).
    - `E` is the current number of edges.
  - Total: `O(queries.length * (V + E))`.

- **Space Complexity:**  
  - Adjacency list: `O(V + E)`.
  - BFS queue: `O(V)`.
