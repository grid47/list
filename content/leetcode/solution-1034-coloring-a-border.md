
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
    
};
{{< /highlight >}}
---


### Problem Statement
The task at hand is to color the border of a connected region in a grid. Each cell in the grid has an integer value representing its color. The goal is to change the color of the border cells of a specified region to a new color while keeping the color of the inner cells intact.

A cell is considered part of the border if it is adjacent to at least one cell that has a different color. The input to the function includes a 2D grid representing the original color configuration, the row and column of the starting cell to begin the coloring process, and the new color to apply to the border.

### Approach
To solve the problem, we employ a depth-first search (DFS) algorithm to explore the grid. The key steps in the approach are as follows:

1. **Depth-First Search (DFS)**: Start from the specified cell and recursively explore its neighboring cells to determine the extent of the region to color. 
2. **Marking Visited Cells**: During the DFS, mark cells that belong to the region with a negative value to avoid revisiting them and to facilitate border detection.
3. **Identifying the Border**: After marking the cells, check each cell to determine if it is a border cell by verifying if it has adjacent cells of different colors.
4. **Coloring the Border**: Finally, change the color of all border cells to the new specified color while restoring the colors of the non-border cells.

### Code Breakdown (Step by Step)

1. **Class Declaration**: The solution is encapsulated within a class named `Solution`.

2. **DFS Function**: 
   - The function `dfs` takes the grid, the current row and column indices, and the color to be checked (cl).
   - It first checks for boundary conditions and ensures that it only processes cells of the specified color.
   - It marks the current cell by negating its value to indicate it has been visited.
   - The function then recursively calls itself for the four neighboring cells (up, down, left, right).
   - Finally, it checks if the current cell is a border cell and restores its original color if all its neighbors are of the same color.
   ```cpp
   void dfs(vector<vector<int>> &grid, int r, int c, int cl) {
       // ...
   }
   ```

3. **Color Border Function**:
   - The `colorBorder` function initializes the DFS from the given starting position and color.
   - It then iterates over the grid, updating each marked cell to the new color and restoring the original colors for cells that were not borders.
   ```cpp
   vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
       dfs(grid, row, col, grid[row][col]);
       // ...
   }
   ```

4. **Grid Size Calculation**: Inside the `colorBorder` function, the size of the grid is determined to facilitate iteration.
   ```cpp
   int m = grid.size(), n = grid[0].size();
   ```

5. **Final Loop to Apply Color**: The function iterates through the entire grid, applying the new border color and restoring non-border cell colors.
   ```cpp
   for(int i = 0; i < m; i++)
       for(int j = 0; j < n; j++)
           grid[i][j] = grid[i][j] < 0 ? color : grid[i][j];
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this solution is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the grid. This is because each cell may be visited once during the DFS and then processed again to apply the new color.
  
- **Space Complexity**: The space complexity is \(O(m \times n)\) in the worst case due to the recursion stack used in DFS if all cells belong to the same region.

### Conclusion
The provided code effectively colors the border of a connected region in a grid using a DFS approach. It accurately identifies and colors border cells while maintaining the integrity of the inner region. 

This solution is efficient for grid-based problems where region detection and coloring are required, and it showcases the power of recursion for traversing multi-dimensional arrays. The clear separation of logic between marking visited cells and identifying borders ensures maintainability and clarity in the implementation.

In summary, the `colorBorder` function is a robust tool for manipulating grid structures, applicable in various scenarios such as game development, image processing, and graphical representation of data.


[`Link to LeetCode Lab`](https://leetcode.com/problems/coloring-a-border/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
