
+++
authors = ["grid47"]
title = "Leetcode 64: Minimum Path Sum"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 64: Minimum Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/64.webp"
youtube = "pGMsrvt0fpk"
youtube_upload_date="2021-07-15"
youtube_thumbnail="https://i.ytimg.com/vi/pGMsrvt0fpk/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/64.webp" 
    alt="A glowing, winding path that minimizes distance, with bright, guiding arrows showing the best route."
    caption="Solution to LeetCode 64: Minimum Path Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
                 if(i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            else if(i > 0) grid[i][j] += grid[i - 1][j];
            else if(j > 0) grid[i][j] += grid[i][j - 1];
        }
        
        return grid[m - 1][n - 1];
    }
};
{{< /highlight >}}
---

### 🛤️ **Minimum Path Sum in Grid**

The problem is to find the minimum path sum from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` of an `m x n` grid. In this grid:
- Each cell contains a non-negative integer that represents the cost to move through that cell.
- Movement is restricted to either down or right at each step.

The goal is to find the path from the starting point to the destination that has the lowest possible sum of costs.

### 🧠 **Approach**

This problem is efficiently solved using **dynamic programming (DP)**, where we calculate the minimum path sum to each cell by building on previously computed values in the grid.

#### Key Observations:
1. **Modifying the Grid in Place**:
   - We update the original `grid` directly to store the cumulative minimum path sum for each cell. This allows us to avoid using extra space, making the solution more memory efficient.

2. **Base Cases**:
   - If the cell is in the first row (i.e., `i == 0`), it can only be reached from the left cell.
   - If the cell is in the first column (i.e., `j == 0`), it can only be reached from the cell above.
   - For all other cells, the minimum path sum to reach `grid[i][j]` is the value of `grid[i][j]` plus the minimum of the values from the cell directly above or to the left.

3. **Recursive Formula**:
   - For each cell `(i, j)` (excluding the first row and column), the minimum path sum is calculated as:
     ```cpp
     grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
     ```
   - This efficiently updates the `grid` with cumulative minimum path sums, ensuring that each cell holds the lowest possible cost to reach it from the start.

### 🔍 **Code Breakdown**

#### Step 1: Initialize Grid Dimensions

```cpp
int m = grid.size(), n = grid[0].size();
```
- Here, `m` is the number of rows, and `n` is the number of columns in the `grid`.

#### Step 2: Iterate Through the Grid

```cpp
for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
```
- The code iterates over each cell `(i, j)` in the `grid`, updating the minimum path sum to reach each cell.

#### Step 3: Update Each Cell

```cpp
if(i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
else if(i > 0) grid[i][j] += grid[i - 1][j];
else if(j > 0) grid[i][j] += grid[i][j - 1];
```
- **General Case**: If the cell `(i, j)` is not in the first row or column, it adds the minimum of the values from the cell above `(i-1, j)` or to the left `(i, j-1)`.
- **First Column**: Cells in the first column can only be reached from the cell above, so they add the value of `grid[i-1][j]`.
- **First Row**: Cells in the first row can only be reached from the left, so they add the value of `grid[i][j-1]`.

#### Step 4: Final Result

```cpp
return grid[m - 1][n - 1];
```
- The value at `grid[m-1][n-1]` contains the minimum path sum to reach the bottom-right corner from the top-left corner.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(m * n)**: We traverse every cell in the `m x n` grid once, making the time complexity `O(m * n)`.

#### Space Complexity:
- **O(1)**: No extra space is used beyond the input grid, as the grid is modified in place to store cumulative minimum path sums.

### 🌟 **Conclusion**

This DP solution is optimal for finding the minimum path sum in a grid with non-negative integers. By modifying the `grid` in place, we efficiently compute the minimum sum, minimizing space complexity. The approach ensures that each cell holds the minimum cost path to reach it, making it a compact and efficient solution for grid-based minimum path problems.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-path-sum/description/)

---
{{< youtube pGMsrvt0fpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
