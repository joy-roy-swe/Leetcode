# Problem: Minimized Maximum of Products Distributed to Any Store

You are given an integer `n`, representing the number of specialty retail stores, and an integer array `quantities` of length `m`, where `quantities[i]` denotes the number of products of the `i`-th product type. The goal is to distribute these products across the stores while following these rules:

1. Each store can only be given **one product type**, but can receive any amount of it.
2. After distribution, each store will have some number of products (possibly `0`).
3. Let `x` be the maximum number of products assigned to any single store. Your objective is to **minimize** this maximum value, `x`.

Return the minimum possible value of `x`.

## Examples

### Example 1
**Input:**  
`n = 6`, `quantities = [11, 6]`

**Output:**  
`3`

**Explanation:**  
One possible optimal distribution is:
- Distribute the `11` products of type `0` across four stores in amounts `[2, 3, 3, 3]`.
- Distribute the `6` products of type `1` across the remaining two stores in amounts `[3, 3]`.

The maximum products assigned to any store is `3`.

### Example 2
**Input:**  
`n = 7`, `quantities = [15, 10, 10]`

**Output:**  
`5`

**Explanation:**  
An optimal distribution is:
- Assign `15` products of type `0` to three stores with amounts `[5, 5, 5]`.
- Assign `10` products of type `1` to two stores with amounts `[5, 5]`.
- Assign `10` products of type `2` to the last two stores with amounts `[5, 5]`.

The maximum load on any store is `5`.

### Example 3
**Input:**  
`n = 1`, `quantities = [100000]`

**Output:**  
`100000`

**Explanation:**  
With only one store, all `100000` products of the only product type must go to this store. Thus, the maximum load is `100000`.

## Constraints
- `m == quantities.length`
- `1 <= m <= n <= 10^5`
- `1 <= quantities[i] <= 10^5`


