# Problem: Maximum Subarray Sum with Distinct Elements

You are given an integer array `nums` and an integer `k`. Your task is to find the maximum subarray sum of all subarrays of `nums` that meet the following conditions:

1. The length of the subarray is `k`.
2. All elements of the subarray are distinct.

If no subarray meets the conditions, return `0`.

A subarray is a contiguous non-empty sequence of elements within an array.

---

## Examples

### Example 1

**Input:**  
`nums = [1,5,4,2,9,9,9]`, `k = 3`

**Output:**  
`15`

**Explanation:**  
The subarrays of `nums` with length `3` are:
- `[1,5,4]` which meets the requirements and has a sum of `10`.
- `[5,4,2]` which meets the requirements and has a sum of `11`.
- `[4,2,9]` which meets the requirements and has a sum of `15`.
- `[2,9,9]` which does not meet the requirements because the element `9` is repeated.
- `[9,9,9]` which does not meet the requirements because the element `9` is repeated.

The maximum sum of a valid subarray is `15`.

---

### Example 2

**Input:**  
`nums = [4,4,4]`, `k = 3`

**Output:**  
`0`

**Explanation:**  
The subarrays of `nums` with length `3` are:
- `[4,4,4]` which does not meet the requirements because the element `4` is repeated.

No subarray meets the conditions, so the result is `0`.

---

## Constraints

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
