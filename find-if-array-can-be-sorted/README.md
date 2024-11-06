# Problem: leetcode 3011. Find if Array Can Be Sorted

You are given a 0-indexed array of positive integers `nums`.

In one operation, you can swap any two adjacent elements if they have the same number of **set bits** (1-bits in their binary representation). You are allowed to perform this operation any number of times (including zero).

Return `true` if you can sort the array, otherwise return `false`.

## Key Concepts

- **Set Bits**: The number of 1s in the binary representation of a number. For example, the number 15 has four set bits since its binary representation is `1111`.

- **Allowed Swap**: You can only swap adjacent elements if they have the same number of set bits.

## Approach

1. **Count Set Bits**: For each number in the array, determine its set bit count.
2. **Group by Set Bit Counts**: Group numbers by their set bit counts. Each group can be independently sorted since numbers with the same set bit count can be swapped with each other.
3. **Check Sorted Order**: If, after sorting each group, the entire array can be placed in ascending order, return `true`. Otherwise, return `false`.

## Examples

### Example 1
**Input:**  
`nums = [8,4,2,30,15]`  

**Output:**  
`true`  

**Explanation:**  
- Binary representations:
  - 2 → `10` (1 set bit)
  - 4 → `100` (1 set bit)
  - 8 → `1000` (1 set bit)
  - 15 → `1111` (4 set bits)
  - 30 → `11110` (4 set bits)
- By swapping elements with the same set bit counts, we can sort the array as `[2,4,8,15,30]`.

### Example 2
**Input:**  
`nums = [1,2,3,4,5]`  

**Output:**  
`true`  

**Explanation:**  
The array is already sorted.

### Example 3
**Input:**  
`nums = [3,16,8,4,2]`  

**Output:**  
`false`  

**Explanation:**  
It is not possible to sort the array with the given swapping condition.

## Constraints

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 28`

