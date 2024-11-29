
+++
authors = ["grid47"]
title = "Leetcode 62: Unique Paths"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 62: Unique Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/62.webp"
youtube = "3ZFvBlynmls"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/3ZFvBlynmls/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/62.webp" 
    alt="A gentle, glowing path winding through a serene landscape, showing multiple routes."
    caption="Solution to LeetCode 62: Unique Paths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A robot starts at the top-left corner of an m x n grid and can only move right or down. Determine the total number of unique paths it can take to reach the bottom-right corner.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two integers, m and n, representing the number of rows and columns of the grid.
- **Example:** `Input: m = 4, n = 5`
- **Constraints:**
	- 1 <= m, n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of unique paths from the top-left to the bottom-right corner of the grid.
- **Example:** `Output: 35`
- **Constraints:**
	- The result will always be less than or equal to 2 * 10^9.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total number of unique paths using dynamic programming or combinatorics.

- Define a 2D DP table where dp[i][j] represents the number of ways to reach cell (i, j).
- Initialize dp[0][j] = 1 for all columns and dp[i][0] = 1 for all rows.
- For each cell dp[i][j], calculate the value as dp[i][j] = dp[i-1][j] + dp[i][j-1].
- Return dp[m-1][n-1] as the final answer.
{{< dots >}}
### Problem Assumptions ✅
- The robot always starts at the top-left corner and ends at the bottom-right corner.
- The robot can only move either down or right.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: m = 4, n = 5`  \
  **Explanation:** There are 35 unique paths from the top-left to the bottom-right corner for a 4x5 grid.

- **Input:** `Input: m = 2, n = 2`  \
  **Explanation:** There are 2 unique paths for a 2x2 grid: Right -> Down and Down -> Right.

- **Input:** `Input: m = 3, n = 4`  \
  **Explanation:** There are 10 unique paths from the top-left to the bottom-right corner for a 3x4 grid.

{{< dots >}}
## Approach 🚀
Use dynamic programming to calculate the number of unique paths, or combinatorics for an optimized solution.

### Initial Thoughts 💭
- The problem can be solved by considering all paths that move exactly m-1 steps down and n-1 steps right.
- A grid cell depends only on the cell above and to the left of it.
- Dynamic programming efficiently calculates the total paths, avoiding repeated calculations.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as input is guaranteed.
- Grid dimensions m = 100, n = 100, which is the maximum size.
- Minimum grid dimensions m = 1, n = 1.
- Ensure the algorithm handles maximum grid dimensions efficiently.
{{< dots >}}
## Code 💻
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
```

This code calculates the number of unique paths from the top-left corner to the bottom-right corner of an m x n grid, where you can only move right or down.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int uniquePaths(int m, int n) {
	```
	This line declares a function named `uniquePaths` that takes two integers `m` and `n` as input, representing the dimensions of the grid, and returns the number of unique paths.

2. **DP Table Initialization**
	```cpp
	    vector<vector<int>> dp(m, vector<int>(n, 0));
	```
	This line initializes a 2D DP table `dp` of size `m x n` to store the number of unique paths to reach each cell. All elements are initially set to 0.

3. **Base Cases: First Row and Column**
	```cpp
	    for (int i = 0; i < m; i++) {
	        for (int j = 0; j < n; j++) {
	            if (i == 0 || j == 0) {
	                dp[i][j] = 1;
	            }
	```
	This nested loop iterates over the first row and first column of the grid. For cells in the first row or first column, there is only one way to reach them, so the corresponding value in the DP table is set to 1.

4. **Calculate Paths for Other Cells**
	```cpp
	else {
	                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	            }
	        }
	    }
	```
	This part of the nested loop iterates over the remaining cells of the grid. For each cell `(i, j)`, the number of unique paths to reach it is the sum of the number of paths to reach the cell above it (`dp[i - 1][j]`) and the number of paths to reach the cell to its left (`dp[i][j - 1]`). This is because we can only move right or down.

5. **Return the Bottom-Right Corner Value**
	```cpp
	    return dp[m - 1][n - 1];
	```
	After filling the DP table, the function returns the value at the bottom-right corner `dp[m - 1][n - 1]`, which represents the total number of unique paths from the top-left to the bottom-right corner.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

Each cell in the grid is visited exactly once to calculate the total paths.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The DP table requires O(m * n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-paths/description/)

---
{{< youtube 3ZFvBlynmls >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
