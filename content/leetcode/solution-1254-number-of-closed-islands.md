
+++
authors = ["grid47"]
title = "Leetcode 1254: Number of Closed Islands"
date = "2024-07-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1254: Number of Closed Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZH8TeWFYpx8"
youtube_upload_date="2023-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/ZH8TeWFYpx8/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D grid with 0s (land) and 1s (water). An island is a group of 0s connected 4-directionally, and a closed island is a group of 0s completely surrounded by 1s. Your task is to count how many closed islands are present in the grid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D grid with 0s and 1s.
- **Example:** `grid = [[1,1,1,1,1,1,1,0], [1,0,0,0,0,1,1,0], [1,0,1,0,1,1,1,0], [1,0,0,0,0,1,0,1], [1,1,1,1,1,1,1,0]]`
- **Constraints:**
	- 1 <= grid.length, grid[0].length <= 100
	- 0 <= grid[i][j] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the number of closed islands.
- **Example:** `Output: 2`
- **Constraints:**
	- The number of closed islands can be at least 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of closed islands in the grid.

- Loop through the grid, marking water cells connected to the boundary.
- Perform a depth-first search (DFS) to explore each closed island.
- Count each closed island and ensure no boundary cell is part of a closed island.
{{< dots >}}
### Problem Assumptions ✅
- The grid is composed of only 0s and 1s.
- Boundary cells are considered to be part of the outer boundary.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[1,1,1,1,1,1,1,0], [1,0,0,0,0,1,1,0], [1,0,1,0,1,1,1,0], [1,0,0,0,0,1,0,1], [1,1,1,1,1,1,1,0]]`  \
  **Explanation:** The grid contains two closed islands, both of which are surrounded by water.

{{< dots >}}
## Approach 🚀
The approach involves marking and counting the closed islands in the grid using a depth-first search (DFS).

### Initial Thoughts 💭
- Boundary cells cannot be part of a closed island.
- Each land cell that is connected to the boundary must be marked as water to avoid counting non-closed islands.
- DFS is a suitable technique to explore all connected land cells of an island.
{{< dots >}}
### Edge Cases 🌐
- Empty grids should return 0.
- Grids with the maximum size (100x100) should be handled efficiently.
- Grids with no water cells should return 0.
- Ensure that the grid size is within the specified limits.
{{< dots >}}
## Code 💻
```cpp
int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
            if(grid[i][j] == 0)
                dfs(grid, i, j, 0, 1);
    int cnt = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 0) {
            dfs(grid, i, j, 0, cnt + 2);
                cnt++;
        }
    return cnt;
}

void dfs(vector<vector<int>>& grid, int i, int j, int cur, int tgt) {
    int m = grid.size(), n = grid[0].size();
    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != cur)
        return;
    grid[i][j] = tgt;
    dfs(grid, i + 1, j, cur, tgt);
    dfs(grid, i, j + 1, cur, tgt);
    dfs(grid, i - 1, j, cur, tgt);
    dfs(grid, i, j - 1, cur, tgt);
}

```

The `closedIsland` function counts the number of closed islands in a given 2D grid, where '0' represents water and '1' represents land. It uses Depth First Search (DFS) to mark the boundary-connected land and then counts isolated areas of land (closed islands). The helper `dfs` function is used to traverse and mark all connected land cells.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int closedIsland(vector<vector<int>>& grid) {
	```
	The function `closedIsland` is defined to take a 2D grid as input, where each cell is either land (1) or water (0). The goal is to find the number of closed islands (i.e., islands surrounded by water).

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	The variables `m` and `n` are initialized to the number of rows and columns of the grid, respectively.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	An outer loop starts that iterates over the rows of the grid.

4. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	An inner loop iterates over the columns of the grid for each row.

5. **Boundary Check**
	```cpp
	        if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
	```
	This checks if the current cell is at the boundary of the grid. The boundary cells are treated differently since they cannot be part of a closed island.

6. **Water Cell Check**
	```cpp
	            if(grid[i][j] == 0)
	```
	If the current cell is a water cell (`0`), the Depth First Search (DFS) function is called to mark all connected water cells along the boundary.

7. **DFS Boundary Marking**
	```cpp
	                dfs(grid, i, j, 0, 1);
	```
	The DFS function is called to mark all water cells connected to the boundary (changing the water cells to a different value to avoid revisiting).

8. **Closed Island Counter**
	```cpp
	    int cnt = 0;
	```
	A counter `cnt` is initialized to keep track of the number of closed islands found in the grid.

9. **Outer Loop (Closed Islands)**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Another outer loop starts to iterate over the rows of the grid to find closed islands.

10. **Inner Loop (Closed Islands)**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	An inner loop starts to iterate over the columns of the grid for each row.

11. **Closed Island Detection**
	```cpp
	        if(grid[i][j] == 0) {
	```
	If a water cell is found that has not been marked during the boundary DFS, it indicates a closed island. The DFS function is called to mark the whole island.

12. **DFS Closed Island Marking**
	```cpp
	            dfs(grid, i, j, 0, cnt + 2);
	```
	The DFS function is called to mark all cells of the current closed island by changing the water cells to a unique value (`cnt + 2`). This also avoids revisiting the same island.

13. **Island Count Increment**
	```cpp
	                cnt++;
	```
	The closed island counter `cnt` is incremented after finding and marking the current island.

14. **Return Statement**
	```cpp
	    return cnt;
	```
	The function returns the total count of closed islands found in the grid.

15. **DFS Function Definition**
	```cpp
	void dfs(vector<vector<int>>& grid, int i, int j, int cur, int tgt) {
	```
	The helper function `dfs` is defined to traverse and mark connected cells of the grid using Depth First Search. It takes the grid, current position (`i`, `j`), the current value to look for (`cur`), and the target value to mark (`tgt`).

16. **DFS Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	The dimensions of the grid (`m` and `n`) are stored in local variables to simplify the condition checks within the DFS function.

17. **DFS Base Condition**
	```cpp
	    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != cur)
	```
	The base case for the DFS function is defined. If the current cell is out of bounds or does not have the expected value (`cur`), the function terminates the search.

18. **DFS Marking**
	```cpp
	        return;
	```
	The DFS function returns if the current cell is out of bounds or not a match for the expected value.

19. **DFS Mark Target**
	```cpp
	    grid[i][j] = tgt;
	```
	The current cell is marked with the target value (`tgt`) to indicate it has been visited or processed.

20. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i + 1, j, cur, tgt);
	```
	The DFS function is called recursively on the cell below the current one.

21. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i, j + 1, cur, tgt);
	```
	The DFS function is called recursively on the cell to the right of the current one.

22. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i - 1, j, cur, tgt);
	```
	The DFS function is called recursively on the cell above the current one.

23. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i, j - 1, cur, tgt);
	```
	The DFS function is called recursively on the cell to the left of the current one.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n) where m and n are the dimensions of the grid.
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

We need to visit every cell in the grid at least once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

In the worst case, we may need additional space for DFS recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-closed-islands/description/)

---
{{< youtube ZH8TeWFYpx8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
