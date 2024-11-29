
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
comments = true
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
Given an m x n grid filled with non-negative integers, find a path from the top-left to the bottom-right corner that minimizes the sum of all numbers along the way. The robot can only move either right or down at each step.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer 2D grid where grid[i][j] represents the cost at cell (i, j).
- **Example:** `Input: grid = [[2,3,4],[5,1,2],[3,2,1]]`
- **Constraints:**
	- m == grid.length
	- n == grid[i].length
	- 1 <= m, n <= 200
	- 0 <= grid[i][j] <= 200

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum sum of numbers along the path from the top-left to the bottom-right corner.
- **Example:** `Output: 10`
- **Constraints:**
	- The result will always be less than or equal to 2 * 10^9.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the path from the top-left to the bottom-right corner of the grid that minimizes the total sum.

- Iterate through each cell of the grid.
- At each cell (i, j), calculate the minimum cost to reach the cell from either the top or the left neighbor.
- For the top row or the leftmost column, only consider cells that exist within the bounds.
- Return the value at the bottom-right corner as the final result.
{{< dots >}}
### Problem Assumptions ✅
- The grid is non-empty and contains at least one cell.
- The top-left corner is always the starting point.
- The bottom-right corner is the destination.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[2,3,4],[5,1,2],[3,2,1]]`  \
  **Explanation:** The path 2 → 3 → 1 → 2 → 1 minimizes the sum, giving an output of 10.

- **Input:** `Input: grid = [[1,4,7],[2,5,6]]`  \
  **Explanation:** The path 1 → 4 → 7 → 6 minimizes the sum, giving an output of 13.

{{< dots >}}
## Approach 🚀
Use a dynamic programming approach to iteratively calculate the minimum path sum for each cell, based on values from its top or left neighbors.

### Initial Thoughts 💭
- The problem involves minimizing the sum, so dynamic programming is suitable.
- Each cell's minimum cost depends on the values of its top and left neighbors.
- Start with the base cases for the top row and leftmost column and build up the solution iteratively.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the input grid is guaranteed to have at least one cell.
- A grid with maximum size (200 x 200) containing large values close to the upper bound (200).
- A grid where all values are zero, resulting in a minimum path sum of 0.
- A grid where the only path is straight down or straight right.
- Ensure that the solution handles edge cases for single-row or single-column grids efficiently.
{{< dots >}}
## Code 💻
```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // Handle the first row
    for (int j = 1; j < n; j++) {
        grid[0][j] += grid[0][j - 1];
    }

    // Handle the first column
    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i - 1][0];
    }

    // Fill the rest of the grid
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    return grid[m - 1][n - 1];
}
```

This code calculates the minimum path sum from the top-left corner to the bottom-right corner of a grid, where you can only move right or down.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minPathSum(vector<vector<int>>& grid) {
	```
	This line declares a function named `minPathSum` that takes a 2D vector `grid` representing the grid as input and returns the minimum path sum.

2. **Get Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line gets the dimensions of the grid, `m` for rows and `n` for columns.

3. **Handle First Row**
	```cpp
	    for (int j = 1; j < n; j++) {
	        grid[0][j] += grid[0][j - 1];
	    }
	```
	This loop iterates over the first row of the grid, starting from the second element. For each cell, it adds the value of the cell to its left to the current cell's value. This represents the minimum path sum to reach that cell from the top-left corner.

4. **Handle First Column**
	```cpp
	    for (int i = 1; i < m; i++) {
	        grid[i][0] += grid[i - 1][0];
	    }
	```
	This loop iterates over the first column of the grid, starting from the second row. For each cell, it adds the value of the cell above it to the current cell's value. This represents the minimum path sum to reach that cell from the top-left corner.

5. **Fill the Rest of the Grid**
	```cpp
	    for (int i = 1; i < m; i++) {
	        for (int j = 1; j < n; j++) {
	            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
	        }
	    }
	```
	This nested loop iterates over the remaining cells of the grid. For each cell `(i, j)`, it calculates the minimum path sum to reach that cell by adding the minimum of the values from the cell above and the cell to the left to the current cell's value.

6. **Return Minimum Path Sum**
	```cpp
	    return grid[m - 1][n - 1];
	```
	After filling the grid with minimum path sums, the function returns the value at the bottom-right corner, which represents the minimum path sum from the top-left to the bottom-right corner.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

Each cell in the grid is visited exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution modifies the input grid in place, requiring no extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-path-sum/description/)

---
{{< youtube pGMsrvt0fpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
