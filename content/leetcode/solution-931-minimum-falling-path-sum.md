
+++
authors = ["grid47"]
title = "Leetcode 931: Minimum Falling Path Sum"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 931: Minimum Falling Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b_F3mz9l-uQ"
youtube_upload_date="2024-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/b_F3mz9l-uQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mtx) {
        
        int m = mtx.size(), n = mtx[0].size();

        for(int i = 1; i < m; i++)
        for(int j = 0; j < n; j++) {

            int l = max(j - 1, 0);
            int r = min(j + 1, n - 1);

            mtx[i][j] += min(mtx[i- 1][l], min(mtx[i - 1][j], mtx[i - 1][r]));

        }

        int res = mtx[m - 1][0];
        for(int j = 0; j < n; j++)
        res = min(res, mtx[m - 1][j]);

        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the minimum sum of a falling path through a matrix. A falling path starts at any element in the first row and chooses one element from each row. For each element, the next row element must be chosen from one of the three possible positions: directly below, or diagonally left or right. The goal is to minimize the sum of the elements along the falling path.

### Approach

This problem can be efficiently solved using **dynamic programming**. The idea is to build a solution incrementally, where each element in the matrix represents the minimum sum of the falling path to reach that element.

#### Key Steps to Solve the Problem:

1. **Dynamic Programming Table (In-Place Modification)**:
   We use the matrix itself to store the intermediate results. For each element in the matrix, the value is updated to represent the minimum sum of a falling path that ends at that element.

2. **Transition**:
   - For each element in the current row, the value is updated by adding the current element to the minimum of the three possible previous elements from the row above (directly above, left-diagonal, right-diagonal).
   - This allows us to "fall" from row to row, choosing the best path while minimizing the sum.

3. **Boundary Considerations**:
   - The first row has no previous row to consider, so it remains unchanged.
   - For each element in a row, we calculate the minimum sum from the previous row, considering only the valid indices (left, center, and right).

4. **Final Result**:
   Once the matrix is updated, the final answer is the minimum value in the last row, as it represents the minimum sum of the falling paths that end in any column of the last row.

### Code Breakdown (Step by Step)

1. **Matrix Dimensions**:
   First, we define `m` and `n` to represent the number of rows and columns in the matrix, respectively.

   ```cpp
   int m = mtx.size(), n = mtx[0].size();
   ```

2. **Dynamic Programming Update**:
   We start from the second row (since the first row doesn't need updating) and update each element. For each element, we consider the three possible positions from the row above (directly above, left-diagonal, right-diagonal). The value of the current element is updated by adding the minimum of these three values.

   ```cpp
   for(int i = 1; i < m; i++)
   for(int j = 0; j < n; j++) {
       int l = max(j - 1, 0);  // Left diagonal (with boundary check)
       int r = min(j + 1, n - 1);  // Right diagonal (with boundary check)

       mtx[i][j] += min(mtx[i-1][l], min(mtx[i-1][j], mtx[i-1][r]));
   }
   ```

   Here, we use `max(j - 1, 0)` to ensure that the left diagonal doesn't go out of bounds, and `min(j + 1, n - 1)` ensures the right diagonal stays within bounds.

3. **Result Calculation**:
   Once the matrix is updated, the result is the minimum value from the last row, as it represents the smallest falling path sum from the first row to the last row.

   ```cpp
   int res = mtx[m - 1][0];  // Start with the first element of the last row
   for(int j = 0; j < n; j++) {
       res = min(res, mtx[m - 1][j]);  // Find the minimum value in the last row
   }
   ```

4. **Return the Result**:
   Finally, we return the result, which is the minimum falling path sum.

   ```cpp
   return res;
   ```

### Time Complexity

The time complexity of this solution is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the matrix. Here's why:
- We loop through each element of the matrix exactly once.
- For each element, we perform constant-time operations (comparing three values and updating the matrix).
  
Thus, the total time complexity is proportional to the size of the matrix.

### Space Complexity

The space complexity is **O(1)** if we modify the matrix in place (as done in this solution). Since we are not using any additional data structures that depend on the size of the input matrix, the space complexity remains constant.

### Edge Cases

- **Single Row Matrix**: If the matrix has only one row, there is no falling path to calculate, so the result is simply the minimum value from that row.
- **Single Column Matrix**: If the matrix has only one column, there is only one path (straight down), and the result is the sum of the elements along that path.
- **Matrix with All Positive Values**: In this case, the algorithm will simply return the minimal sum path based on the grid structure.
- **Matrix with All Negative Values**: The algorithm still works for negative values, but it will find the path that results in the least negative sum.
- **Empty Matrix**: The solution assumes a non-empty matrix, but handling an empty matrix can be done by checking for this case at the start and returning `0`.

### Conclusion

The solution to this problem efficiently computes the minimum sum of a falling path using dynamic programming. By modifying the input matrix in-place, we reduce the space complexity to **O(1)** while maintaining an **O(m * n)** time complexity, which is optimal for this problem. This method is not only efficient but also straightforward, making it an ideal approach for solving matrix-related dynamic programming problems involving path sums.

By applying this approach, you can handle larger input sizes efficiently while maintaining clarity in the solution's logic. The use of the sliding window (for each element's left and right neighbors) ensures that we consider only valid transitions, which makes the solution robust and adaptable to various types of grid configurations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-falling-path-sum/description/)

---
{{< youtube b_F3mz9l-uQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
