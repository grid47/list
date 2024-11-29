
+++
authors = ["grid47"]
title = "Leetcode 1020: Number of Enclaves"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1020: Number of Enclaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BcrKHwawGb8"
youtube_upload_date="2023-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/BcrKHwawGb8/maxresdefault.jpg"
comments = true
+++



---
You are given a grid of size m x n where each cell is either land (1) or sea (0). Your task is to determine the number of land cells that are completely enclosed by sea cells. A land cell is considered enclosed if it cannot reach the boundary of the grid via other land cells.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n grid, where grid[i][j] is either 1 (land) or 0 (sea).
- **Example:** `grid = [[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]`
- **Constraints:**
	- 1 <= m, n <= 500
	- grid[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of land cells that are completely enclosed by sea cells, i.e., they cannot reach the boundary of the grid.
- **Example:** `Output: 3`
- **Constraints:**
	- The returned number should be an integer representing the count of enclosed land cells.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine which land cells are enclosed, we need to find and mark all the land cells connected to the boundary of the grid, and then count the remaining land cells.

- 1. Traverse the boundary of the grid and mark all land cells connected to it using depth-first search (DFS).
- 2. After marking the reachable land cells, the remaining unmarked land cells are enclosed.
- 3. Count and return the number of enclosed land cells.
{{< dots >}}
### Problem Assumptions ✅
- The input grid is valid and contains only 0s and 1s.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]`  \
  **Explanation:** In this case, the 1s in positions (1, 0), (1, 2), and (2, 1) are enclosed by 0s. The land cell at position (2, 2) is not enclosed because it is connected to the boundary. Thus, the output is 3.

- **Input:** `Input: grid = [[0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0]]`  \
  **Explanation:** In this case, all the 1s are either connected to the boundary or can reach the boundary through other land cells. Therefore, no land cells are enclosed, and the output is 0.

{{< dots >}}
## Approach 🚀
The approach uses depth-first search (DFS) to mark all land cells connected to the boundary, then counts the remaining unmarked land cells.

### Initial Thoughts 💭
- Boundary cells can directly or indirectly reach the edge, so any land cell connected to the boundary is not enclosed.
- The problem requires marking the land cells that are connected to the boundary using DFS and then counting the unmarked ones.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty or contains no land cells, the output should be 0.
- For large grids (e.g., 500 x 500), the algorithm should still run within time limits.
- Handle cases where all cells are sea cells (0) or all cells are land cells (1).
- Ensure the solution handles the maximum grid size efficiently.
{{< dots >}}
## Code 💻
```cpp
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
            if(grid[i][j] == 1)
                dfs(grid, i, j);
    int cnt = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 1) cnt++;
    
    return cnt;
}

void dfs(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
        return;
    grid[i][j] = 2;
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
```

The function `numEnclaves` counts the number of enclaves (connected cells of 1's) in a grid. The grid's boundary is checked first, marking cells connected to the boundary using DFS. Then it counts the remaining cells that are completely enclosed by 0's.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numEnclaves(vector<vector<int>>& grid) {
	```
	Defines the function `numEnclaves`, which takes a 2D grid as input and returns the number of enclaves (connected regions of 1's that are not connected to the boundary).

2. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Stores the number of rows `m` and columns `n` in the grid, which are used to iterate over the grid.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Starts the first loop to iterate through each row of the grid.

4. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Starts the inner loop to iterate through each column of the current row.

5. **Boundary Check**
	```cpp
	        if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
	```
	Checks if the current cell is on the boundary of the grid (first row, first column, last row, or last column).

6. **Condition for DFS**
	```cpp
	            if(grid[i][j] == 1)
	```
	If the current boundary cell contains a 1 (representing land), it calls the `dfs` function to mark all connected land cells.

7. **DFS Call**
	```cpp
	                dfs(grid, i, j);
	```
	Calls the helper function `dfs` to mark all connected 1's from the current cell as visited (by setting them to 2).

8. **Count Initialization**
	```cpp
	    int cnt = 0;
	```
	Initializes a counter `cnt` to store the number of remaining land cells that are not connected to the boundary.

9. **Count Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Starts a loop to iterate through each row again to count the remaining land cells.

10. **Count Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Starts an inner loop to iterate through each column of the current row.

11. **Count Update**
	```cpp
	        if(grid[i][j] == 1) cnt++;
	```
	Increments the counter `cnt` whenever a land cell (1) is found that is not connected to the boundary.

12. **Return Count**
	```cpp
	    return cnt;
	```
	Returns the final count of the enclaves (land cells not connected to the boundary).

13. **Helper Function Declaration**
	```cpp
	void dfs(vector<vector<int>>& grid, int i, int j) {
	```
	Defines the helper function `dfs` that uses Depth-First Search to mark connected land cells starting from position `(i, j)`. It modifies the grid to mark visited cells.

14. **DFS Base Case**
	```cpp
	    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
	```
	Checks for out-of-bounds conditions or if the current cell is not land (value is not 1). If any of these conditions are true, the function exits.

15. **Exit DFS**
	```cpp
	        return;
	```
	Exits the DFS function if the cell is invalid or already visited.

16. **Mark Visited Cell**
	```cpp
	    grid[i][j] = 2;
	```
	Marks the current cell as visited by setting its value to 2.

17. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i + 1, j);
	```
	Recursively calls `dfs` on the cell below the current cell.

18. **DFS Recursive Call**
	```cpp
	    dfs(grid, i, j + 1);
	```
	Recursively calls `dfs` on the cell to the right of the current cell.

19. **DFS Recursive Call**
	```cpp
	    dfs(grid, i - 1, j);
	```
	Recursively calls `dfs` on the cell above the current cell.

20. **DFS Recursive Call**
	```cpp
	    dfs(grid, i, j - 1);
	```
	Recursively calls `dfs` on the cell to the left of the current cell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we are iterating over every cell in the grid, performing a DFS traversal for each boundary land cell.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the recursion stack used by DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-enclaves/description/)

---
{{< youtube BcrKHwawGb8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
