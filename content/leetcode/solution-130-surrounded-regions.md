
+++
authors = ["grid47"]
title = "Leetcode 130: Surrounded Regions"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 130: Surrounded Regions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/130.webp"
youtube = "9z2BunfoZ5Y"
youtube_upload_date="2021-08-16"
youtube_thumbnail="https://i.ytimg.com/vi/9z2BunfoZ5Y/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/130.webp" 
    alt="A grid of cells gently surrounded by a calming border of light, with certain areas being 'captured."
    caption="Solution to LeetCode 130: Surrounded Regions Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n matrix board containing letters 'X' and 'O'. Capture all regions that are surrounded by 'X'. A region is captured if it is surrounded by 'X' cells and cannot reach the edges of the board.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an m x n matrix containing 'X' and 'O'. Each element represents a cell of the board.
- **Example:** `[['X','X','X','X'], ['X','O','O','X'], ['X','X','O','X'], ['X','O','X','X']]`
- **Constraints:**
	- 1 <= m, n <= 200
	- board[i][j] is either 'X' or 'O'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a matrix where all 'O' regions that are surrounded by 'X' cells are captured by replacing 'O' with 'X'.
- **Example:** `[['X','X','X','X'], ['X','X','X','X'], ['X','X','X','X'], ['X','O','X','X']]`
- **Constraints:**
	- The output will be a modified version of the input board with captured 'O' regions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to capture the regions of 'O' surrounded by 'X'.

- 1. Traverse the entire board to identify 'O' cells on the borders (edges).
- 2. Use a depth-first search (DFS) to mark the 'O' cells connected to the borders as safe.
- 3. After the traversal, replace all remaining 'O' cells (surrounded regions) with 'X'.
- 4. Restore all 'O' cells marked as safe back to 'O'.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid matrix where m and n are within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `[['X','X','X','X'], ['X','O','O','X'], ['X','X','O','X'], ['X','O','X','X']]`  \
  **Explanation:** In this case, 'O's that are surrounded by 'X's (not touching the edge) are captured and turned into 'X's.

- **Input:** `[['X']]`  \
  **Explanation:** This board has no 'O's, so no cells are captured and the board remains unchanged.

{{< dots >}}
## Approach 🚀
Use depth-first search (DFS) to mark all 'O' cells connected to the borders, then modify the matrix accordingly.

### Initial Thoughts 💭
- The 'O' cells on the borders and connected to them are safe, and need to be preserved.
- The remaining 'O' cells are surrounded and need to be captured.
- The problem can be solved efficiently by marking the border-connected 'O' cells as safe using DFS, and then replacing all remaining 'O's with 'X'.
{{< dots >}}
### Edge Cases 🌐
- If the board is empty or contains only 'X', no changes are made.
- The algorithm should be efficient enough to handle the maximum constraints of m, n <= 200.
- If the board contains no 'O' cells, no modifications will occur.
- The board will contain at least one row and one column.
{{< dots >}}
## Code 💻
```cpp
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(i == 0 || j == 0 || i == m - 1|| j == n -1)
            if(board[i][j] == 'O')
                dfs(board, i, j);
    
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(board[i][j] == 'O')
            board[i][j] = 'X';
        else if(board[i][j] == '1')
            board[i][j] = 'O';
    
}

void dfs(vector<vector<char>> &grid, int i, int j) {
    if(i < 0 || j < 0 || i == grid.size() || 
       j == grid[0].size() || grid[i][j] != 'O')
        return;
    grid[i][j] = '1';
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
```

This solution marks all regions surrounded by 'X' on a 2D board, transforming all 'O's that are not connected to the border into 'X'. It uses Depth-First Search (DFS) to explore the connected 'O' cells.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void solve(vector<vector<char>>& board) {
	```
	Define the function `solve` that takes a 2D grid `board` as input and modifies it in-place to solve the problem.

2. **Matrix Dimensions**
	```cpp
	    int m = board.size(), n = board[0].size();
	```
	Get the dimensions of the grid: `m` represents the number of rows and `n` represents the number of columns.

3. **Outer Loop Iteration**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start an outer loop to iterate over each row of the board.

4. **Inner Loop Iteration**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Start an inner loop to iterate over each column of the current row.

5. **Boundary Check**
	```cpp
	        if(i == 0 || j == 0 || i == m - 1|| j == n -1)
	```
	Check if the current position is at the border of the grid (first or last row/column).

6. **O Check**
	```cpp
	            if(board[i][j] == 'O')
	```
	Check if the current cell is 'O', indicating a potential region to explore.

7. **DFS Call**
	```cpp
	                dfs(board, i, j);
	```
	Call the `dfs` function to perform Depth-First Search and mark all connected 'O's starting from the current cell.

8. **Second Outer Loop Iteration**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start the second iteration over the rows of the grid to modify the cells based on DFS results.

9. **Second Inner Loop Iteration**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Iterate over the columns of each row in the second pass.

10. **O Replacement**
	```cpp
	        if(board[i][j] == 'O')
	```
	Check if the current cell is 'O' that was not connected to the border (should be surrounded by 'X').

11. **Mark X**
	```cpp
	            board[i][j] = 'X';
	```
	Change the isolated 'O' to 'X' since it is surrounded by 'X'.

12. **Restore O**
	```cpp
	        else if(board[i][j] == '1')
	```
	Check if the current cell was marked as '1' during the DFS, indicating it is part of a border-connected region.

13. **Restore O**
	```cpp
	            board[i][j] = 'O';
	```
	Restore the 'O' at this position since it was connected to the border.

14. **DFS Function Declaration**
	```cpp
	void dfs(vector<vector<char>> &grid, int i, int j) {
	```
	Define the `dfs` function that performs Depth-First Search to explore connected regions of 'O'.

15. **Base Case Check**
	```cpp
	    if(i < 0 || j < 0 || i == grid.size() || 
	```
	Check if the current position is out of bounds of the grid.

16. **DFS Exit Condition**
	```cpp
	       j == grid[0].size() || grid[i][j] != 'O')
	```
	Check if the current cell is not 'O' (i.e., already visited or not a valid cell for DFS).

17. **Return Statement**
	```cpp
	        return;
	```
	Exit the DFS function if the base case is met.

18. **Mark as Visited**
	```cpp
	    grid[i][j] = '1';
	```
	Mark the current cell as visited by changing it to '1'.

19. **Recursive DFS Calls**
	```cpp
	    dfs(grid, i + 1, j);
	```
	Recursively call `dfs` to explore the cell below the current one.

20. **Recursive DFS Calls**
	```cpp
	    dfs(grid, i, j + 1);
	```
	Recursively call `dfs` to explore the cell to the right of the current one.

21. **Recursive DFS Calls**
	```cpp
	    dfs(grid, i - 1, j);
	```
	Recursively call `dfs` to explore the cell above the current one.

22. **Recursive DFS Calls**
	```cpp
	    dfs(grid, i, j - 1);
	```
	Recursively call `dfs` to explore the cell to the left of the current one.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns.
- **Average Case:** O(m * n), since we traverse all cells at least once.
- **Worst Case:** O(m * n), since we may need to explore all cells in the matrix.

The time complexity is linear with respect to the size of the board.

### Space Complexity 💾
- **Best Case:** O(1), if no extra space is used (except for temporary marking).
- **Worst Case:** O(m * n), since we might use extra space for the DFS stack in the worst case.

The space complexity is dependent on the recursion depth of DFS, but in practice it is O(m * n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/surrounded-regions/description/)

---
{{< youtube 9z2BunfoZ5Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
