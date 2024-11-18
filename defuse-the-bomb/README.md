# Problem: Defuse the Bomb

You are given a circular array `code` of length `n` and an integer `k`. To defuse the bomb, you must decrypt the `code` by replacing every number simultaneously based on the following rules:

- If `k > 0`, replace the `i`-th number with the sum of the next `k` numbers.
- If `k < 0`, replace the `i`-th number with the sum of the previous `k` numbers.
- If `k == 0`, replace the `i`-th number with `0`.

Since the array is circular:
- The next element of `code[n-1]` is `code[0]`.
- The previous element of `code[0]` is `code[n-1]`.

Return the decrypted code as an array.

## Examples

### Example 1
**Input:**  
`code = [5,7,1,4]`, `k = 3`

**Output:**  
`[12,10,16,13]`

**Explanation:**  
Each number is replaced by the sum of the next 3 numbers.  
The decrypted code is calculated as:
- `code[0] = 7 + 1 + 4 = 12`
- `code[1] = 1 + 4 + 5 = 10`
- `code[2] = 4 + 5 + 7 = 16`
- `code[3] = 5 + 7 + 1 = 13`

### Example 2
**Input:**  
`code = [1,2,3,4]`, `k = 0`

**Output:**  
`[0,0,0,0]`

**Explanation:**  
When `k = 0`, all numbers are replaced by `0`.

### Example 3
**Input:**  
`code = [2,4,9,3]`, `k = -2`

**Output:**  
`[12,5,6,13]`

**Explanation:**  
Each number is replaced by the sum of the previous 2 numbers.  
The decrypted code is calculated as:
- `code[0] = 3 + 9 = 12`
- `code[1] = 2 + 3 = 5`
- `code[2] = 4 + 2 = 6`
- `code[3] = 9 + 4 = 13`

## Constraints
- `n == code.length`
- `1 <= n <= 100`
- `1 <= code[i] <= 100`
- `-(n - 1) <= k <= n - 1`
