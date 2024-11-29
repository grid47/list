
+++
authors = ["grid47"]
title = "Leetcode 417: Pacific Atlantic Water Flow"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 417: Pacific Atlantic Water Flow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/417.webp"
youtube = "1HDq998kmio"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1HDq998kmio/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/417.webp" 
    alt="A map with water flowing from both Pacific and Atlantic oceans, gently meeting at highlighted points."
    caption="Solution to LeetCode 417: Pacific Atlantic Water Flow Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n grid representing an island, where each cell contains an integer representing the height above sea level. The island borders both the Pacific and Atlantic Oceans. The Pacific Ocean touches the left and top edges of the grid, and the Atlantic Ocean touches the right and bottom edges. Water can flow from one cell to an adjacent cell if the adjacent cell's height is less than or equal to the current cell's height. The task is to find all the cells where water can flow to both oceans.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D integer grid representing the heights of the island cells.
- **Example:** `Input: heights = [[3,4,5],[6,7,8],[1,2,3]]`
- **Constraints:**
	- 1 <= m, n <= 200
	- 0 <= heights[r][c] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of coordinates that represent the cells where water can flow to both the Pacific and Atlantic Oceans.
- **Example:** `Output: [[0,2],[1,1],[2,0]]`
- **Constraints:**
	- The output should be a list of valid cell coordinates.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify all the cells where water can flow to both oceans.

- Use depth-first search (DFS) to explore cells from the borders of both oceans.
- Mark cells that can reach the Pacific Ocean from the top and left borders.
- Mark cells that can reach the Atlantic Ocean from the bottom and right borders.
- Return cells that can reach both oceans.
{{< dots >}}
### Problem Assumptions ✅
- The grid represents a valid island structure.
- Water can flow to any neighboring cell that is lower or equal in height.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: heights = [[3,4,5],[6,7,8],[1,2,3]]`  \
  **Explanation:** In this example, the cells that can flow to both the Pacific and Atlantic oceans are (0,2), (1,1), and (2,0). Water flows from these cells to both oceans as demonstrated in the DFS exploration.

{{< dots >}}
## Approach 🚀
To solve this problem, we use DFS to explore the cells that can reach the Pacific and Atlantic Oceans, marking them as we go.

### Initial Thoughts 💭
- The problem asks to find all cells that can reach both oceans.
- We can perform DFS starting from the borders of the grid where water can reach the ocean.
- By marking the cells reachable from the Pacific and Atlantic Oceans separately, we can identify cells that are reachable from both.
{{< dots >}}
### Edge Cases 🌐
- If the grid has no rows or columns, the result should be an empty list.
- Ensure that the solution can handle grids with the maximum size efficiently.
- All cells have the same height: In this case, all cells can reach both oceans.
- The solution should efficiently handle the maximum constraints of 200x200 grid size.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pac(m, vector<bool>(n, false));
    vector<vector<bool>> atl(m, vector<bool>(n, false));
    for(int j = 0; j < n; j++) {
        dfs(heights, pac, 0, j);
        dfs(heights, atl, m -1, j);            
    }
    for(int j = 0; j < m; j++) {
        dfs(heights, pac, j, 0);
        dfs(heights, atl, j, n - 1);            
    }
    vector<vector<int>> ans;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(pac[i][j] && atl[i][j])
            ans.push_back({i, j});
    return ans;
}

void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j) {
    
    vis[i][j] = true;
    if(i > 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
        dfs(h, vis, i - 1, j);
    if(j > 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
        dfs(h, vis, i, j - 1);
    if(i < h.size() - 1 && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
        dfs(h, vis, i + 1, j);
    if(j < h[0].size() - 1 && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
        dfs(h, vis, i, j + 1);
    
}

```

This code finds the cells in a matrix representing elevations that can reach both the Pacific and Atlantic oceans. The method uses depth-first search (DFS) to mark reachable cells starting from the edges of the matrix for both oceans.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	```
	This line declares the `pacificAtlantic` function, which takes a 2D vector representing the elevation map and returns a 2D vector with the coordinates that can reach both oceans.

2. **Variable Initialization**
	```cpp
	    int m = heights.size(), n = heights[0].size();
	```
	Here, we initialize variables `m` and `n` to represent the number of rows and columns in the heights matrix.

3. **2D Vector Initialization**
	```cpp
	    vector<vector<bool>> pac(m, vector<bool>(n, false));
	```
	This initializes a 2D boolean vector `pac` to track whether each cell can reach the Pacific Ocean. Initially, all values are set to `false`.

4. **2D Vector Initialization**
	```cpp
	    vector<vector<bool>> atl(m, vector<bool>(n, false));
	```
	Similarly, this initializes the 2D boolean vector `atl` to track whether each cell can reach the Atlantic Ocean.

5. **Loop Initialization**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This starts a loop to iterate over each column in the first and last row to perform DFS.

6. **DFS Call**
	```cpp
	        dfs(heights, pac, 0, j);
	```
	This calls the `dfs` function to mark all cells reachable from the Pacific Ocean (starting from the first row).

7. **DFS Call**
	```cpp
	        dfs(heights, atl, m -1, j);            
	```
	Similarly, this calls the `dfs` function to mark all cells reachable from the Atlantic Ocean (starting from the last row).

8. **Loop Initialization**
	```cpp
	    for(int j = 0; j < m; j++) {
	```
	This starts a loop to iterate over each row in the first and last column to perform DFS.

9. **DFS Call**
	```cpp
	        dfs(heights, pac, j, 0);
	```
	This calls the `dfs` function to mark all cells reachable from the Pacific Ocean (starting from the first column).

10. **DFS Call**
	```cpp
	        dfs(heights, atl, j, n - 1);            
	```
	This calls the `dfs` function to mark all cells reachable from the Atlantic Ocean (starting from the last column).

11. **Variable Declaration**
	```cpp
	    vector<vector<int>> ans;
	```
	This initializes a vector `ans` to store the coordinates of cells that can reach both the Pacific and Atlantic oceans.

12. **Nested Loop Initialization**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This starts a loop to iterate over each row.

13. **Nested Loop Initialization**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This starts a nested loop to iterate over each column.

14. **Condition Check**
	```cpp
	        if(pac[i][j] && atl[i][j])
	```
	This checks if a cell can reach both the Pacific and Atlantic oceans.

15. **Push Result**
	```cpp
	            ans.push_back({i, j});
	```
	If a cell can reach both oceans, its coordinates are added to the `ans` vector.

16. **Return Statement**
	```cpp
	    return ans;
	```
	Finally, the function returns the list of coordinates that can reach both the Pacific and Atlantic oceans.

17. **Function Declaration**
	```cpp
	void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j) {
	```
	This declares the `dfs` function, which performs depth-first search to mark reachable cells for a given ocean.

18. **DFS Marking**
	```cpp
	    vis[i][j] = true;
	```
	This marks the current cell as visited.

19. **DFS Recursive Calls**
	```cpp
	    if(i > 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
	```
	This checks if the top neighbor cell is within bounds, has not been visited, and is higher or equal in elevation.

20. **DFS Recursive Calls**
	```cpp
	        dfs(h, vis, i - 1, j);
	```
	If the condition is true, it recursively calls `dfs` for the top neighbor.

21. **DFS Recursive Calls**
	```cpp
	    if(j > 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
	```
	This checks if the left neighbor cell is within bounds, has not been visited, and is higher or equal in elevation.

22. **DFS Recursive Calls**
	```cpp
	        dfs(h, vis, i, j - 1);
	```
	If the condition is true, it recursively calls `dfs` for the left neighbor.

23. **DFS Recursive Calls**
	```cpp
	    if(i < h.size() - 1 && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
	```
	This checks if the bottom neighbor cell is within bounds, has not been visited, and is higher or equal in elevation.

24. **DFS Recursive Calls**
	```cpp
	        dfs(h, vis, i + 1, j);
	```
	If the condition is true, it recursively calls `dfs` for the bottom neighbor.

25. **DFS Recursive Calls**
	```cpp
	    if(j < h[0].size() - 1 && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
	```
	This checks if the right neighbor cell is within bounds, has not been visited, and is higher or equal in elevation.

26. **DFS Recursive Calls**
	```cpp
	        dfs(h, vis, i, j + 1);
	```
	If the condition is true, it recursively calls `dfs` for the right neighbor.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns in the grid.
- **Average Case:** O(m * n), as DFS will explore each cell in the worst case.
- **Worst Case:** O(m * n), since we may need to explore all cells.

The time complexity is linear with respect to the size of the grid.

### Space Complexity 💾
- **Best Case:** O(m * n), as the worst-case space is determined by the grid size.
- **Worst Case:** O(m * n), as we need space for the DFS stack and the two boolean grids for marking cells.

The space complexity is proportional to the size of the grid due to the storage of the DFS stack and the visited grids.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)

---
{{< youtube 1HDq998kmio >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
