
+++
authors = ["grid47"]
title = "Leetcode 1034: Coloring A Border"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1034: Coloring A Border in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an m x n grid of integers where each value represents the color of a cell. You are also given three integers: `row`, `col`, and `color`. The task is to change the color of the border of the connected component containing the cell at `grid[row][col]`. A connected component is defined as a group of adjacent cells that have the same color. A border cell is a cell that is either adjacent to a different color cell or is on the boundary of the grid. You should return the updated grid where the border of the connected component is colored with the specified color.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a grid represented by an m x n matrix, with each element representing the color of the corresponding grid cell. You are also given integers `row`, `col`, and `color`, indicating the starting position and the new color to apply to the border.
- **Example:** `grid = [[1, 2, 2], [3, 2, 2], [4, 4, 2]], row = 1, col = 1, color = 5`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= grid[i][j], color <= 1000
	- 0 <= row < m
	- 0 <= col < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the modified grid with the border of the connected component colored with the specified color.
- **Example:** `Output: [[1, 5, 5], [3, 2, 5], [4, 4, 5]]`
- **Constraints:**
	- The modified grid must have the new border color applied correctly.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the connected component of cells starting from `grid[row][col]`, and then change the color of the border cells of that component to the given color.

- 1. Use Depth-First Search (DFS) to explore the connected component starting from the cell at `grid[row][col]`.
- 2. Mark the cells in the connected component to differentiate them from other cells while exploring.
- 3. Identify border cells by checking if they are adjacent to a different color or on the boundary of the grid.
- 4. Update the color of the border cells to the given color.
- 5. Restore the grid by changing the cells back to their original values after processing.
{{< dots >}}
### Problem Assumptions ✅
- The grid contains only valid integers representing colors, and no out-of-bound accesses occur.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1, 1], [1, 2]], row = 0, col = 0, color = 3`  \
  **Explanation:** The connected component containing grid[0][0] is the cell at position [0][0]. The border cells are [0][1] and [1][0], which are colored with the new color 3. The output is [[3, 3], [3, 2]].

- **Input:** `Input: grid = [[1, 2, 2], [2, 3, 2]], row = 0, col = 1, color = 3`  \
  **Explanation:** The connected component starts from grid[0][1], and the border cells are [0][0], [0][2], and [1][1]. The output after coloring the border is [[1, 3, 3], [2, 3, 3]].

{{< dots >}}
## Approach 🚀
The approach involves performing a depth-first search to identify all the connected cells and then updating the border cells with the given color.

### Initial Thoughts 💭
- The problem involves identifying connected components and updating border cells. A DFS approach can help efficiently identify the connected component.
- By marking cells during the DFS traversal and checking their neighbors, we can easily identify border cells and update their color.
{{< dots >}}
### Edge Cases 🌐
- Since the grid has at least one cell, there will be no empty input.
- For large inputs, the solution should work efficiently within the constraint limits of a grid size of 50x50.
- The color should only be applied to the border cells of the connected component.
- Ensure the DFS traversal doesn't go out of bounds or misinterpret border cells.
{{< dots >}}
## Code 💻
```cpp
void dfs(vector<vector<int>> &grid, int r, int c, int cl) {
 
    int m = grid.size();
    int n = grid[0].size();
    if(r < 0 || c < 0 || r >=  m || c >= n || grid[r][c] != cl) return;

    grid[r][c] = -cl;
    
    dfs(grid, r + 1, c, cl);
    dfs(grid, r - 1, c, cl);
    dfs(grid, r, c + 1, cl);
    dfs(grid, r, c - 1, cl);
    
    if(  r > 0 && c > 0 && r < m -1 && c < n - 1 &&
        abs(grid[r+1][c]) == cl && abs(grid[r-1][c]) == cl && 
        abs(grid[r][c+1]) == cl && abs(grid[r][c-1]) == cl )
    {
         grid[r][c] = cl;
    }  
    
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    dfs(grid, row, col, grid[row][col]);
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        grid[i][j] = grid[i][j] < 0? color:grid[i][j];
    return grid;
}

```

This complete function identifies and colors the border of a connected component in a 2D grid using a DFS approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void dfs(vector<vector<int>> &grid, int r, int c, int cl) {
	```
	Define the depth-first search (DFS) function to traverse the grid.

2. **Initialize Dimensions**
	```cpp
	    int m = grid.size();
	```
	Initialize `m` as the number of rows in the grid.

3. **Initialize Dimensions**
	```cpp
	    int n = grid[0].size();
	```
	Initialize `n` as the number of columns in the grid.

4. **Boundary Check**
	```cpp
	    if(r < 0 || c < 0 || r >=  m || c >= n || grid[r][c] != cl) return;
	```
	Check if the current cell is out of bounds or not part of the connected component.

5. **Mark Visited**
	```cpp
	    grid[r][c] = -cl;
	```
	Mark the cell as visited by assigning a temporary negative value.

6. **Recursive Call**
	```cpp
	    dfs(grid, r + 1, c, cl);
	```
	Call DFS recursively for the cell below.

7. **Recursive Call**
	```cpp
	    dfs(grid, r - 1, c, cl);
	```
	Call DFS recursively for the cell above.

8. **Recursive Call**
	```cpp
	    dfs(grid, r, c + 1, cl);
	```
	Call DFS recursively for the cell to the right.

9. **Recursive Call**
	```cpp
	    dfs(grid, r, c - 1, cl);
	```
	Call DFS recursively for the cell to the left.

10. **Restore Inner Cells**
	```cpp
	    if(  r > 0 && c > 0 && r < m -1 && c < n - 1 &&
	```
	Check if the cell is surrounded by other cells with the same value.

11. **Restore Inner Cells**
	```cpp
	         abs(grid[r+1][c]) == cl && abs(grid[r-1][c]) == cl &&
	```
	Confirm that all adjacent cells belong to the same connected component.

12. **Restore Inner Cells**
	```cpp
	         abs(grid[r][c+1]) == cl && abs(grid[r][c-1]) == cl )
	```
	Verify all four directions for connected component consistency.

13. **Restore Inner Cells**
	```cpp
	         grid[r][c] = cl;
	```
	Restore the cell value if it is not a border.

14. **Main Function Definition**
	```cpp
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
	```
	Define the main function to color the border of the connected component.

15. **Call DFS**
	```cpp
	    dfs(grid, row, col, grid[row][col]);
	```
	Initiate DFS traversal from the specified cell.

16. **Iterate Grid**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Iterate through the grid rows.

17. **Iterate Grid**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Iterate through the grid columns.

18. **Color Border**
	```cpp
	        grid[i][j] = grid[i][j] < 0? color:grid[i][j];
	```
	Update the grid, assigning the new color to the border cells.

19. **Return Result**
	```cpp
	    return grid;
	```
	Return the modified grid with the colored border.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) since we need to traverse each cell in the grid at least once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the recursive DFS calls and auxiliary storage for marking visited cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/coloring-a-border/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
