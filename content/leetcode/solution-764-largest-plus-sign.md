
+++
authors = ["grid47"]
title = "Leetcode 764: Largest Plus Sign"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 764: Largest Plus Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/764.webp"
youtube = "dOSQVrCtO9w"
youtube_upload_date="2021-09-09"
youtube_thumbnail="https://i.ytimg.com/vi/dOSQVrCtO9w/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/764.webp" 
    alt="A grid where the largest plus sign is found, glowing softly as the shape is identified."
    caption="Solution to LeetCode 764: Largest Plus Sign Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer n, which represents the size of an n x n binary grid. Initially, all the values in the grid are set to 1, except for some indices that are specified in the array mines. Your task is to find the order of the largest axis-aligned plus sign of 1's in the grid. A plus sign of order k has a center grid[r][c] == 1 with arms extending in all four directions (up, down, left, right) of length k - 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n and an array mines where each element is a pair of integers [xi, yi] indicating the grid coordinates that are 0.
- **Example:** `Input: n = 6, mines = [[3, 2], [1, 3]]`
- **Constraints:**
	- 1 <= n <= 500
	- 1 <= mines.length <= 5000
	- 0 <= xi, yi < n
	- All the pairs (xi, yi) are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the order of the largest plus sign of 1's contained in the grid. If there is no such plus sign, return 0.
- **Example:** `Output: 2`
- **Constraints:**
	- The returned order will be an integer representing the largest possible order of the plus sign.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the largest order of a plus sign in the binary grid considering the mines at the specified positions.

- Initialize a grid of size n x n with all 1's.
- Set the specified mines in the grid to 0.
- For each cell, compute the maximum length of the plus sign arms in all four directions.
- Track the maximum possible order of the plus sign.
{{< dots >}}
### Problem Assumptions ✅
- The grid initially contains all 1's, and mines are specified as 0's.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: n = 6, mines = [[3, 2], [1, 3]]`  \
  **Explanation:** In this case, the grid can form a plus sign of order 2, with arms extending in all four directions.

{{< dots >}}
## Approach 🚀
We can solve the problem by first marking the positions of the mines and then calculating the largest possible plus sign by examining the grid's arms in each direction.

### Initial Thoughts 💭
- The size of the grid is manageable, but we need to handle up to 5000 mines.
- The plus sign is formed from the center, so we need to compute the possible length of arms in each direction.
- A dynamic approach can help by computing the maximum arm lengths as we iterate over the grid.
{{< dots >}}
### Edge Cases 🌐
- If n is 1 and the only cell is a mine, return 0.
- Ensure that the solution works efficiently for the largest possible grid size and number of mines.
- If no mines are specified, the entire grid may form a plus sign.
- Handle edge cases like small grid sizes and grids with multiple mines.
{{< dots >}}
## Code 💻
```cpp
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    vector<vector<int>> grid(n, vector<int>(n, n));
    for(auto &m: mines)
    grid[m[0]][m[1]] = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
        grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0? 0: l + 1));
        grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0? 0: r + 1));
        grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0? 0: u + 1));
        grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0? 0: d + 1));
    }

    int res = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        res = max(grid[i][j], res);

    return res;

}
```

This code implements the algorithm to find the largest plus sign that can be formed on a grid after marking certain cells as blocked, where the blocked cells are provided by the input mines. It iterates through each cell, updating values based on the nearest blocked cells in all four directions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
	```
	This line declares the function `orderOfLargestPlusSign`, which takes the size of the grid (`n`) and a list of mines as inputs, and returns an integer representing the order of the largest plus sign.

2. **Grid Initialization**
	```cpp
	    vector<vector<int>> grid(n, vector<int>(n, n));
	```
	This line initializes a 2D grid of size `n x n` with all values set to `n`, indicating the largest possible size of a plus sign at each point initially.

3. **Mines Loop**
	```cpp
	    for(auto &m: mines)
	```
	This loop iterates over the list of `mines`, where each mine represents a blocked cell in the grid.

4. **Marking Mines**
	```cpp
	    grid[m[0]][m[1]] = 0;
	```
	For each mine, this line sets the corresponding grid cell to 0, marking it as a blocked cell.

5. **Grid Processing Start**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This outer loop iterates through each row of the grid.

6. **Grid Processing Inner Loop**
	```cpp
	    for(int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
	```
	This inner loop processes each column of the grid. It also initializes variables for left, right, up, and down direction counts.

7. **Left Direction Calculation**
	```cpp
	        grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0? 0: l + 1));
	```
	This line updates the grid value in the left direction, setting the number of consecutive non-zero cells.

8. **Right Direction Calculation**
	```cpp
	        grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0? 0: r + 1));
	```
	This line updates the grid value in the right direction, counting consecutive non-zero cells.

9. **Up Direction Calculation**
	```cpp
	        grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0? 0: u + 1));
	```
	This line updates the grid value in the upward direction, counting consecutive non-zero cells.

10. **Down Direction Calculation**
	```cpp
	        grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0? 0: d + 1));
	```
	This line updates the grid value in the downward direction, counting consecutive non-zero cells.

11. **Result Initialization**
	```cpp
	    int res = 0;
	```
	This line initializes a variable `res` to keep track of the maximum order of the plus sign.

12. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This outer loop iterates through each row of the grid again.

13. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This inner loop iterates through each column of the grid.

14. **Finding Maximum**
	```cpp
	        res = max(grid[i][j], res);
	```
	This line updates `res` with the maximum value from the grid, which represents the largest order of the plus sign.

15. **Return Result**
	```cpp
	    return res;
	```
	This line returns the result, which is the order of the largest plus sign found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2) where n is the size of the grid, as we need to process each cell in the grid.
- **Average Case:** O(n^2) for grids of typical size with up to 5000 mines.
- **Worst Case:** O(n^2) in the worst case, as we need to check every cell for the largest plus sign.

Time complexity is quadratic due to the two nested loops required to process each cell.

### Space Complexity 💾
- **Best Case:** O(n^2) as we store the grid and the arms information for each cell.
- **Worst Case:** O(n^2) due to the space used by the grid.

Space complexity is quadratic because we maintain an n x n grid and additional variables for calculating arm lengths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-plus-sign/description/)

---
{{< youtube dOSQVrCtO9w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
