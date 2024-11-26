# Problem: Determine the Tournament Champion

In a tournament with `n` teams numbered from `0` to `n - 1`, each team represents a node in a Directed Acyclic Graph (DAG). You are tasked to find the champion of the tournament.

---

## Problem Statement

You are given:

- An integer `n`, the number of teams.
- A 0-indexed 2D integer array `edges` of length `m`, where `edges[i] = [uᵢ, vᵢ]` indicates a directed edge from team `uᵢ` to team `vᵢ`.

### Definitions

1. A directed edge from team `a` to team `b` means:
   - Team `a` is stronger than team `b`.
   - Team `b` is weaker than team `a`.

2. A team `a` will be the **champion** if there is no other team `b` such that `b` is stronger than `a`.

3. A Directed Acyclic Graph (DAG) does not contain cycles.

### Task

Return the team that will be the champion if:
- There is a **unique champion**, otherwise return `-1`.

---

## Notes

- A **cycle** is a sequence of nodes `a₁, a₂, ..., aₙ, a₁` where:
  - `a₁ = aₙ` (starting and ending node are the same).
  - All nodes `a₁, a₂, ..., aₙ` are distinct.
  - There is a directed edge from `aᵢ` to `aᵢ₊₁` for all `i` in the range `[1, n]`.

---

## Examples

### Example 1

**Input:**  
`n = 3`, `edges = [[0,1],[1,2]]`

**Output:**  
`0`

**Explanation:**  
- Team `1` is weaker than team `0`.
- Team `2` is weaker than team `1`.  
So, team `0` is the champion.

---

### Example 2

**Input:**  
`n = 4`, `edges = [[0,2],[1,3],[1,2]]`

**Output:**  
`-1`

**Explanation:**  
- Team `2` is weaker than teams `0` and `1`.
- Team `3` is weaker than team `1`.  
But neither team `1` nor team `0` is weaker than any other team.  
Thus, there is no unique champion.

---

## Constraints

- `1 <= n <= 100`
- `m == edges.length`
- `0 <= m <= n * (n - 1) / 2`
- `edges[i].length == 2`
- `0 <= edge[i][j] <= n - 1`
- `edges[i][0] != edges[i][1]`
- The input guarantees:
  - If team `a` is stronger than team `b`, then team `b` is not stronger than team `a`.
  - If team `a` is stronger than team `b` and team `b` is stronger than team `c`, then team `a` is stronger than team `c`.

---

## Approach

### Step 1: Compute In-degrees
- Calculate the in-degree for every node. The in-degree of a node represents the number of teams stronger than that node.
- A potential champion will have an **in-degree of 0** (no stronger teams).

### Step 2: Check for Uniqueness
- If more than one node has an in-degree of `0`, return `-1` (no unique champion).
- If exactly one node has an in-degree of `0`, that node is the champion.

### Step 3: Validate DAG Properties
- Use topological sorting to ensure that the graph is a valid DAG.

---

## Algorithm

1. **Initialize Variables:**
   - An array `in_degree` of size `n` initialized to `0`.

2. **Calculate In-degrees:**
   - For each edge `[u, v]`, increment `in_degree[v]` by `1`.

3. **Identify Candidates:**
   - Count the nodes with an in-degree of `0`.
   - If there is more than one candidate, return `-1`.

4. **Topological Sort Validation (Optional):**
   - Perform a topological sort to ensure no cycles exist.

5. **Return the Result:**
   - If exactly one node has in-degree `0`, return that node.
   - Otherwise, return `-1`.

---

## Complexity

- **Time Complexity:** `O(n + m)`  
  - `O(m)` for calculating in-degrees.
  - `O(n + m)` for topological sorting.

- **Space Complexity:** `O(n + m)`  
  - For storing the graph and the in-degree array.

---