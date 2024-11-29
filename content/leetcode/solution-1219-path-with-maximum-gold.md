
+++
authors = ["grid47"]
title = "Leetcode 1219: Path with Maximum Gold"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1219: Path with Maximum Gold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I1wllM_pozY"
youtube_upload_date="2024-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/I1wllM_pozY/maxresdefault.jpg"
comments = true
+++



---
In a gold mine grid of size m x n, each cell contains an integer representing the amount of gold in that cell. A cell with 0 means no gold is present. The task is to find the maximum amount of gold that can be collected by following certain movement rules: You can move one step in any of the four directions (left, right, up, down), but you cannot visit the same cell twice, and you cannot move to a cell that contains 0 gold.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid where each cell contains an integer representing the amount of gold. A value of 0 means no gold is present in the cell.
- **Example:** `Input: grid = [[0, 6, 0], [5, 8, 7], [0, 9, 0]]`
- **Constraints:**
	- 1 <= m, n <= 15
	- 0 <= grid[i][j] <= 100
	- There are at most 25 cells containing gold.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum amount of gold that can be collected under the given movement constraints.
- **Example:** `Output: 24`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum amount of gold that can be collected, we need to explore the grid and recursively calculate the maximum gold collected from each valid starting point.

- Traverse each cell in the grid. If the cell contains gold, recursively explore all four directions (up, down, left, right).
- Track the gold collected along the path and ensure that you don't revisit cells or step on a cell with 0 gold.
- Return the maximum gold collected from any starting cell.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always contain at least one cell with gold.
- The grid size will not exceed 15 x 15.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[0, 6, 0], [5, 8, 7], [0, 9, 0]]`  \
  **Explanation:** The path to collect the maximum gold is 9 → 8 → 7, collecting a total of 24 units of gold.

- **Input:** `Input: grid = [[1, 0, 7], [2, 0, 6], [3, 4, 5], [0, 3, 0], [9, 0, 20]]`  \
  **Explanation:** The path to collect the maximum gold is 1 → 2 → 3 → 4 → 5 → 6 → 7, collecting a total of 28 units of gold.

{{< dots >}}
## Approach 🚀
We will use a Depth-First Search (DFS) to explore all potential paths starting from each cell with gold, keeping track of the maximum gold collected along the way.

### Initial Thoughts 💭
- Each cell can be a potential starting point, and we need to explore all four directions recursively.
- We should mark cells as visited while exploring to avoid revisiting them, then backtrack once we've explored all possible paths from a given cell.
{{< dots >}}
### Edge Cases 🌐
- The grid will never be empty, as there will always be at least one cell containing gold.
- The grid can have a maximum size of 15x15, which is manageable for a DFS approach.
- Handle grids where all non-zero cells are isolated or surrounded by cells with no gold.
- The solution must operate within the given grid size and constraints, ensuring it runs efficiently even for the largest grids.
{{< dots >}}
## Code 💻
```cpp
int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int maxGold = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            maxGold = max(maxGold, findMax(grid, m, n, i, j));
    return maxGold;
}

int dir[5] = {0,1,0,-1,0};

int findMax(vector<vector<int>> &grid, int m,int n, int r, int c) {
    if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
        return 0;
    int origin = grid[r][c];
    grid[r][c] = 0;
    int mx = 0;
    for(int i = 0; i < 4; i++)
        mx = max(mx, findMax(grid, m, n, r+dir[i], c+dir[i+1]));
    grid[r][c]=origin;
    return mx+origin;
}
```

This solution finds the maximum amount of gold that can be collected from a grid of cells, where each cell contains a certain amount of gold. The algorithm uses depth-first search (DFS) to explore the grid and calculate the maximum gold that can be collected starting from any valid cell.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getMaximumGold(vector<vector<int>>& grid) {
	```
	Define the function `getMaximumGold`, which takes a 2D grid representing the map of gold amounts, and returns the maximum amount of gold that can be collected by traversing the grid.

2. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Store the number of rows (`m`) and columns (`n`) of the grid in variables for later use.

3. **Max Gold Initialization**
	```cpp
	    int maxGold = 0;
	```
	Initialize a variable `maxGold` to 0. This will store the maximum amount of gold collected from any starting cell.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start an outer loop that iterates over each row in the grid.

5. **Inner Loop**
	```cpp
	        for(int j = 0; j < n; j++)
	```
	Start an inner loop that iterates over each column in the current row.

6. **Max Gold Update**
	```cpp
	            maxGold = max(maxGold, findMax(grid, m, n, i, j));
	```
	For each cell in the grid, call the helper function `findMax` to calculate the maximum amount of gold that can be collected from that starting cell, and update `maxGold` accordingly.

7. **Return Max Gold**
	```cpp
	    return maxGold;
	```
	Return the value of `maxGold`, which contains the maximum amount of gold that can be collected from the grid.

8. **Direction Array Initialization**
	```cpp
	int dir[5] = {0,1,0,-1,0};
	```
	Initialize an array `dir` to represent the four possible directions of movement in the grid: right, down, left, and up.

9. **Helper Function Definition**
	```cpp
	int findMax(vector<vector<int>> &grid, int m,int n, int r, int c) {
	```
	Define the helper function `findMax`, which performs depth-first search (DFS) starting from the cell at coordinates `(r, c)` in the grid.

10. **Base Case Check**
	```cpp
	    if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
	```
	Check if the current cell is out of bounds or contains a value of 0 (no gold). If any of these conditions is true, return 0, as no gold can be collected from this cell.

11. **Store Origin Value**
	```cpp
	        return 0;
	```
	Return 0 if the cell is out of bounds or empty, ending the current DFS exploration.

12. **Save Current Cell Value**
	```cpp
	    int origin = grid[r][c];
	```
	Store the current value of the cell (amount of gold) in the `origin` variable, as we will modify the grid during DFS.

13. **Mark Cell as Visited**
	```cpp
	    grid[r][c] = 0;
	```
	Mark the current cell as visited by setting its value to 0, preventing revisiting the same cell during DFS.

14. **Max Gold Initialization in DFS**
	```cpp
	    int mx = 0;
	```
	Initialize a variable `mx` to track the maximum gold that can be collected from neighboring cells during the DFS.

15. **DFS Loop**
	```cpp
	    for(int i = 0; i < 4; i++)
	```
	Start a loop to explore the four possible directions from the current cell.

16. **Recursive DFS Call**
	```cpp
	        mx = max(mx, findMax(grid, m, n, r+dir[i], c+dir[i+1]));
	```
	Recursively call the `findMax` function for each direction, updating `mx` with the maximum value returned by each DFS exploration.

17. **Restore Cell Value**
	```cpp
	    grid[r][c]=origin;
	```
	Restore the original value of the current cell to ensure the grid is unchanged for other DFS explorations.

18. **Return Max Gold from Current Cell**
	```cpp
	    return mx+origin;
	```
	Return the maximum amount of gold that can be collected starting from the current cell, including the gold in the current cell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

In the worst case, we may need to explore each cell multiple times for each DFS call, leading to a time complexity of O(m * n).

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the recursive call stack and the need to store the grid's state during exploration.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-with-maximum-gold/description/)

---
{{< youtube I1wllM_pozY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
