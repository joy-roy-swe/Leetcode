# Largest Rectangle in Binary Matrix

Given a `rows` x `cols` binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

## Example:

**Input:**  
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

**Output:**  
6

**Explanation:**  
The maximal rectangle is shown in the above picture.

**Input:**  
matrix = [["0"]]

**Output:**  
0

**Input:**  
matrix = [["1"]]

**Output:**  
1

## Constraints:

- `rows == matrix.length`
- `cols == matrix[i].length`
- 1 <= rows, cols <= 200
- matrix[i][j] is '0' or '1'.
