
+++
authors = ["grid47"]
title = "Leetcode 695: Max Area of Island"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 695: Max Area of Island in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/695.webp"
youtube = "rowp_Frq_eI"
youtube_upload_date="2024-05-07"
youtube_thumbnail="https://i.ytimg.com/vi/rowp_Frq_eI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/695.webp" 
    alt="A map of islands where the maximum area is calculated and softly glowing as the largest island is found."
    caption="Solution to LeetCode 695: Max Area of Island Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a binary matrix of size m x n, where 1 represents land and 0 represents water. An island is a group of 1's connected horizontally or vertically. Return the area of the largest island. If there are no islands, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary matrix of size m x n.
- **Example:** `grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],...]`
- **Constraints:**
	- 1 <= m, n <= 50
	- grid[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the area of the largest island. If no island exists, return 0.
- **Example:** `6`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the area of the largest island by performing a depth-first search (DFS) to count the number of connected land cells for each island.

- Loop through the grid and find the first land cell (1).
- Start a DFS from that cell to explore the entire island.
- Keep track of the size of the current island during the DFS.
- Update the maximum area whenever a larger island is found.
- Repeat this process until all cells have been explored.
{{< dots >}}
### Problem Assumptions ✅
- The grid is non-empty.
- The values in the grid are either 0 or 1, representing water or land, respectively.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],...]`  \
  **Explanation:** In this example, the largest island has 6 cells. The DFS explores each land cell and counts the connected land cells to determine the island's size.

- **Input:** `Example 2: grid = [[0,0,0,0,0,0,0,0]]`  \
  **Explanation:** Since there are no land cells in this grid, the result is 0.

{{< dots >}}
## Approach 🚀
We can solve this problem using a depth-first search (DFS) approach. The idea is to traverse the grid and perform DFS for each unvisited land cell, counting the area of each island.

### Initial Thoughts 💭
- DFS is well-suited for exploring connected components (islands).
- We need to keep track of the largest area found.
- For each unvisited land cell, we'll use DFS to find the area of the island it belongs to.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty, return 0.
- Ensure the solution works efficiently for grids with the maximum size.
- If all cells are water, return 0.
- If all cells are land, return the total number of cells.
- Handle cases where the grid contains isolated islands of varying sizes.
{{< dots >}}
## Code 💻
```cpp
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int mx = 0;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 1)
            mx = max(mx, dfs(grid, i, j));
    return mx;
}

int dfs(vector<vector<int>>& grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1)
        return 0;
    int ans = 1;
    grid[i][j] = 2;
    ans += dfs(grid, i + 1, j);
    ans += dfs(grid, i, j + 1);
    ans += dfs(grid, i - 1, j);
    ans += dfs(grid, i, j - 1);
    return ans;
}
```

This code defines a function to calculate the maximum area of an island in a 2D grid. It uses a depth-first search (DFS) approach to explore all connected land cells (represented by 1s) and calculates the area of the island by recursively marking visited cells. The outer function iterates over the grid and calls the DFS for each unvisited land cell, updating the maximum area found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int maxAreaOfIsland(vector<vector<int>>& grid) {
	```
	This defines the `maxAreaOfIsland` function, which takes a 2D grid representing the island and returns the area of the largest island (connected land cells).

2. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	This initializes a variable `mx` to store the maximum area of the island found so far.

3. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This retrieves the number of rows (`m`) and columns (`n`) in the grid.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This outer loop iterates through each row in the grid.

5. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This inner loop iterates through each column in the current row.

6. **Condition Check**
	```cpp
	        if(grid[i][j] == 1)
	```
	This condition checks if the current cell is land (represented by 1).

7. **DFS Call**
	```cpp
	            mx = max(mx, dfs(grid, i, j));
	```
	If the current cell is land, it calls the `dfs` function to calculate the area of the island starting from this cell, and updates `mx` with the maximum area found.

8. **Return Statement**
	```cpp
	    return mx;
	```
	After checking all the cells in the grid, this returns the maximum area of the island found.

9. **DFS Method Definition**
	```cpp
	int dfs(vector<vector<int>>& grid, int i, int j) {
	```
	This defines the `dfs` function, which explores all connected land cells and calculates the area of the island starting from the given coordinates.

10. **Grid Dimensions (DFS)**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This retrieves the number of rows (`m`) and columns (`n`) in the grid for the DFS function.

11. **Base Case Check**
	```cpp
	    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1)
	```
	This checks if the current coordinates are out of bounds or if the current cell is not land. If so, the DFS returns 0 (no area).

12. **Return Zero**
	```cpp
	        return 0;
	```
	If the base case is met (out of bounds or water), the DFS returns 0.

13. **Initialize Area**
	```cpp
	    int ans = 1;
	```
	This initializes the area for the current island to 1 (the current cell itself).

14. **Mark Visited**
	```cpp
	    grid[i][j] = 2;
	```
	This marks the current cell as visited by changing its value to 2 (from land to water).

15. **Recursive DFS**
	```cpp
	    ans += dfs(grid, i + 1, j);
	```
	This recursively calls `dfs` to explore the cell below the current cell.

16. **Recursive DFS**
	```cpp
	    ans += dfs(grid, i, j + 1);
	```
	This recursively calls `dfs` to explore the cell to the right of the current cell.

17. **Recursive DFS**
	```cpp
	    ans += dfs(grid, i - 1, j);
	```
	This recursively calls `dfs` to explore the cell above the current cell.

18. **Recursive DFS**
	```cpp
	    ans += dfs(grid, i, j - 1);
	```
	This recursively calls `dfs` to explore the cell to the left of the current cell.

19. **Return Area**
	```cpp
	    return ans;
	```
	This returns the total area of the island found by the DFS function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

In the worst case, we may need to visit every cell in the grid, hence the time complexity is O(m * n).

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the DFS recursion stack, which could potentially explore all cells in the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-area-of-island/description/)

---
{{< youtube rowp_Frq_eI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
