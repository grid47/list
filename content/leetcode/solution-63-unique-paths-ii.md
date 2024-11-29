
+++
authors = ["grid47"]
title = "Leetcode 63: Unique Paths II"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 63: Unique Paths II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/63.webp"
youtube = "d3UOz7zdE4I"
youtube_upload_date="2023-02-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d3UOz7zdE4I/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/63.webp" 
    alt="A more intricate, glowing path system with a few obstacles, showing varied routes to the goal."
    caption="Solution to LeetCode 63: Unique Paths II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
A robot starts at the top-left corner of an m x n grid and needs to reach the bottom-right corner. The grid contains obstacles (marked as 1) and empty cells (marked as 0). The robot can only move down or right and cannot pass through cells with obstacles. Determine the number of unique paths to the destination.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer 2D array grid where grid[i][j] is either 0 (empty) or 1 (obstacle).
- **Example:** `Input: obstacleGrid = [[0,0,1],[0,0,0],[1,0,0]]`
- **Constraints:**
	- m == obstacleGrid.length
	- n == obstacleGrid[i].length
	- 1 <= m, n <= 100
	- obstacleGrid[i][j] is 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unique paths from the top-left to the bottom-right corner while avoiding obstacles.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will always be less than or equal to 2 * 10^9.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the total number of unique paths from start to destination while avoiding obstacles using dynamic programming.

- Initialize a DP table with dimensions m x n to store the number of ways to reach each cell.
- Set dp[0][0] = 1 if grid[0][0] == 0; otherwise set dp[0][0] = 0.
- For each cell (i, j), if grid[i][j] == 0, calculate dp[i][j] as the sum of paths from the top and left neighbors.
- If grid[i][j] == 1, set dp[i][j] = 0 as it is an obstacle.
- Return dp[m-1][n-1] as the final result.
{{< dots >}}
### Problem Assumptions ✅
- The robot starts at grid[0][0] and ends at grid[m-1][n-1].
- A cell marked with 1 is an obstacle and cannot be part of any path.
- The robot can only move down or right.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: obstacleGrid = [[0,0,1],[0,0,0],[1,0,0]]`  \
  **Explanation:** There are three unique paths from the top-left to the bottom-right corner avoiding obstacles.

- **Input:** `Input: obstacleGrid = [[0,0,0],[0,1,0],[0,1,0]]`  \
  **Explanation:** There is only one unique path that avoids obstacles.

{{< dots >}}
## Approach 🚀
Use a dynamic programming approach to calculate the total paths, where cells with obstacles are marked as 0.

### Initial Thoughts 💭
- The problem requires handling obstacles, making it different from the regular unique paths problem.
- Cells with obstacles contribute 0 paths and block traversal.
- Dynamic programming can be adapted by marking obstacle cells as 0.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as input is guaranteed.
- Maximum grid size with m = 100 and n = 100, with scattered obstacles.
- A grid where the start or end cell is blocked (grid[0][0] or grid[m-1][n-1] = 1).
- Ensure the algorithm handles all obstacles efficiently.
{{< dots >}}
## Code 💻
```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Handle the case where the starting cell is an obstacle
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // Initialize the first cell as 1, as there's only one way to reach it
    dp[0][0] = 1;

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
    }

    // Fill the first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
    }

    // Fill the rest of the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
```

This code calculates the number of unique paths from the top-left corner to the bottom-right corner of a grid with obstacles, where you can only move right or down.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	```
	This line declares a function named `uniquePathsWithObstacles` that takes a 2D vector `obstacleGrid` representing the grid with obstacles as input and returns the number of unique paths.

2. **Get Grid Dimensions**
	```cpp
	    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	```
	This line gets the dimensions of the grid, `m` for rows and `n` for columns.

3. **Initialize DP Table**
	```cpp
	    vector<vector<int>> dp(m, vector<int>(n, 0));
	```
	This line initializes a 2D DP table `dp` of size `m x n` to store the number of unique paths to reach each cell. All elements are initially set to 0.

4. **Handle Starting Obstacle**
	```cpp
	    if (obstacleGrid[0][0] == 1) {
	        return 0;
	    }
	```
	This condition checks if the starting cell is an obstacle. If so, there are no possible paths, so the function returns 0.

5. **Initialize Starting Cell**
	```cpp
	    dp[0][0] = 1;
	```
	If the starting cell is not an obstacle, it's initialized with 1, as there's only one way to reach it.

6. **Fill First Row**
	```cpp
	    for (int j = 1; j < n; j++) {
	        dp[0][j] = obstacleGrid[0][j] == 0 ? dp[0][j - 1] : 0;
	    }
	```
	This loop fills the first row of the DP table. For each cell, if it's not an obstacle, the number of paths to reach it is the same as the number of paths to reach the cell to its left. Otherwise, it's 0.

7. **Fill First Column**
	```cpp
	    for (int i = 1; i < m; i++) {
	        dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
	    }
	```
	This loop fills the first column of the DP table. For each cell, if it's not an obstacle, the number of paths to reach it is the same as the number of paths to reach the cell above it. Otherwise, it's 0.

8. **Fill the Rest of the DP Table**
	```cpp
	    for (int i = 1; i < m; i++) {
	        for (int j = 1; j < n; j++) {
	            if (obstacleGrid[i][j] == 0) {
	                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	            }
	        }
	    }
	```
	This nested loop fills the rest of the DP table. For each cell `(i, j)` that is not an obstacle, the number of paths to reach it is the sum of the number of paths to reach the cell above it and the cell to its left.

9. **Return the Bottom-Right Corner Value**
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

Each cell is visited exactly once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The DP table requires O(m * n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-paths-ii/description/)

---
{{< youtube d3UOz7zdE4I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
