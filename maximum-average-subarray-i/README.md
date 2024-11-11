# Problem: Maximum Average Subarray of Length k

Given an integer array `nums` with `n` elements, and an integer `k`, the task is to find a contiguous subarray of length `k` with the maximum average value and return this value.

The solution should return any answer with a calculation error less than `10^-5`.

## Examples

### Example 1
**Input:**  
`nums = [1,12,-5,-6,50,3]`, `k = 4`

**Output:**  
`12.75000`

**Explanation:**  
- The subarray `[12, -5, -6, 50]` has the maximum sum of `51`.
- Average = `51 / 4 = 12.75`.

### Example 2
**Input:**  
`nums = [5]`, `k = 1`

**Output:**  
`5.00000`

**Explanation:**  
- The only subarray of length 1 is `[5]`, so the maximum average is `5.0`.

## Constraints

- `n == nums.length`
- `1 <= k <= n <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Approach

1. **Sliding Window Technique**:
   - Use a sliding window of size `k` to maintain the sum of the current subarray of length `k`.
   - Initially, calculate the sum of the first `k` elements.
   - For each subsequent element, adjust the sum by removing the element that slides out of the window and adding the new element that enters the window.
   - Track the maximum sum encountered during this process.
   
2. **Calculate the Maximum Average**:
   - Divide the maximum sum by `k` to get the maximum average.

3. **Return Result**:
   - Return the maximum average found, ensuring that it has an error margin within `10^-5`.

This approach has a time complexity of `O(n)`, as each element is processed only once.
