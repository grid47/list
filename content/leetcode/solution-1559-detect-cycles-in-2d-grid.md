
+++
authors = ["grid47"]
title = "Leetcode 1559: Detect Cycles in 2D Grid"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1559: Detect Cycles in 2D Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eQvsVEt_j8M"
youtube_upload_date="2020-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/eQvsVEt_j8M/maxresdefault.jpg"
comments = true
+++



---
Given a 2D grid of characters, find if there exists a cycle where the same character repeats in the grid. A cycle is defined as a path where a character appears 4 or more times, forming a loop that starts and ends at the same cell. The cycle must consist of adjacent cells, and you are not allowed to revisit the previous cell.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array of characters representing the grid, where the size of the grid is m x n. The grid only contains lowercase English letters.
- **Example:** `Input: grid = [['a', 'b', 'a'], ['b', 'a', 'b'], ['a', 'b', 'a']]`
- **Constraints:**
	- 1 <= m, n <= 500
	- grid consists only of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if there is a cycle of the same character in the grid, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to identify if there exists a cycle in the grid where a character repeats in a loop of 4 or more cells.

- Iterate through all cells in the grid.
- For each unvisited cell, perform a depth-first search (DFS) to find a cycle of the same character.
- Keep track of the previous cell to avoid revisiting it in the next step.
- If a cycle is found, return true, else continue to the next cell.
- Return false if no cycle is found.
{{< dots >}}
### Problem Assumptions ✅
- A cycle must consist of at least 4 cells.
- The cycle must only consist of adjacent cells in one of four directions (up, down, left, right).
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grid = [['a', 'a', 'a', 'a'], ['a', 'b', 'b', 'a'], ['a', 'b', 'b', 'a'], ['a', 'a', 'a', 'a']]`  \
  **Explanation:** There are two valid cycles in the grid: one cycle in the top-left corner and another one in the bottom-right corner.

- **Input:** `Example 2: grid = [['a', 'b', 'a'], ['b', 'a', 'b'], ['a', 'b', 'a']]`  \
  **Explanation:** There is no valid cycle in this grid as the characters don't form a loop of length 4 or more.

{{< dots >}}
## Approach 🚀
The problem can be solved using depth-first search (DFS) to detect cycles in the grid. During the DFS, we keep track of the path to ensure we don't revisit the last cell in the cycle.

### Initial Thoughts 💭
- The grid can have up to 500 x 500 cells, so an efficient search is needed.
- The DFS will be used to explore each unvisited cell and check for cycles.
- A DFS approach ensures we can explore all possible cycles starting from each cell.
{{< dots >}}
### Edge Cases 🌐
- An empty grid would return false since there are no cells to form a cycle.
- For large grids (500 x 500), ensure the DFS is optimized to prevent time limit exceeded errors.
- A grid with only one character may form a valid cycle if the path length is sufficient.
- Ensure that the grid size does not exceed the maximum constraints.
{{< dots >}}
## Code 💻
```cpp
bool containsCycle(vector<vector<char>>& grid) {

    int m = grid.size(), n = grid[0].size();
    
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    
    for(int i = 0; i < m; i++) 
    for(int j = 0; j < n; j++) 
    if(!vis[i][j] && dfs(grid, vis, i, j, -1, -1, grid[i][j])) return true;
    
    return false;
    
}

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int pi, int pj, char node) {
    
    if(vis[i][j]) return true;
    
    vis[i][j] = true;

    for(auto d: dir) {
        int ni = i + d[0];
        int nj = j + d[1];
        
        if(min(ni, nj) < 0 || 
           ni > grid.size() - 1 || 
           nj > grid[0].size() - 1 ||
           grid[ni][nj] != node)
            continue;
        if((ni == pi) && (nj == pj)) continue;
        
        if(dfs(grid, vis, ni, nj, i, j, node))
            return true;
        
    }
    
    return false;
    
}

```

The function `containsCycle` checks if a grid contains a cycle. It uses DFS (Depth-First Search) to traverse through the grid and track whether a cycle exists based on the movement directions. The function also utilizes a `vis` array to mark visited cells and avoid revisiting them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool containsCycle(vector<vector<char>>& grid) {
	```
	This is the function definition for `containsCycle`. It takes a 2D grid of characters (`grid`) and checks if there exists a cycle in the grid. The function returns a boolean value indicating whether a cycle is detected.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line calculates the number of rows `m` and columns `n` of the grid.

3. **Variable Initialization**
	```cpp
	    vector<vector<bool>> vis(m, vector<bool>(n, false));
	```
	This line initializes a 2D vector `vis` of size `m x n` to track visited cells. All elements are initially set to `false`.

4. **Loop Iteration**
	```cpp
	    for(int i = 0; i < m; i++) 
	```
	The outer for loop iterates through all rows in the grid, represented by the variable `i`.

5. **Loop Iteration**
	```cpp
	    for(int j = 0; j < n; j++) 
	```
	The inner for loop iterates through all columns in the current row, represented by the variable `j`.

6. **Condition Check**
	```cpp
	    if(!vis[i][j] && dfs(grid, vis, i, j, -1, -1, grid[i][j])) return true;
	```
	If the current cell has not been visited and a cycle is detected using DFS starting from that cell, the function immediately returns `true`.

7. **Return Statement**
	```cpp
	    return false;
	```
	If no cycle is found in the grid after traversing all cells, the function returns `false`.

8. **Global Variable**
	```cpp
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	```
	This line defines a global variable `dir` that holds the possible movement directions (right, left, down, up) for DFS traversal in the grid.

9. **Function Declaration**
	```cpp
	bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int pi, int pj, char node) {
	```
	This is the DFS function declaration. It checks for cycles by recursively visiting neighboring cells and marking cells as visited.

10. **Condition Check**
	```cpp
	    if(vis[i][j]) return true;
	```
	If the current cell has already been visited, it means a cycle has been detected, so the function returns `true`.

11. **Mark Visited**
	```cpp
	    vis[i][j] = true;
	```
	The current cell is marked as visited in the `vis` array to avoid revisiting it in future iterations.

12. **Loop Iteration**
	```cpp
	    for(auto d: dir) {
	```
	This loop iterates over each of the four possible movement directions (right, left, down, up) defined in `dir`.

13. **Variable Update**
	```cpp
	        int ni = i + d[0];
	```
	This calculates the new row index `ni` based on the current direction `d[0]`.

14. **Variable Update**
	```cpp
	        int nj = j + d[1];
	```
	This calculates the new column index `nj` based on the current direction `d[1]`.

15. **Bounds Check**
	```cpp
	        if(min(ni, nj) < 0 || ni > grid.size() - 1 || nj > grid[0].size() - 1 || grid[ni][nj] != node)
	```
	This checks if the new position `(ni, nj)` is out of bounds or if the character in the grid at that position does not match the current node.

16. **Skip Invalid Move**
	```cpp
	            continue;
	```
	If the new position is invalid or does not match the current node, the loop continues to the next direction.

17. **Skip Parent**
	```cpp
	        if((ni == pi) && (nj == pj)) continue;
	```
	If the new position is the parent of the current cell (i.e., the cell from which the current DFS call originated), the loop continues to avoid revisiting the parent.

18. **Recursive Call**
	```cpp
	        if(dfs(grid, vis, ni, nj, i, j, node))
	```
	If the DFS call to the neighboring cell returns `true`, it indicates that a cycle has been found, so `true` is returned.

19. **Return Statement**
	```cpp
	    return false;
	```
	If no cycle is found during the DFS, `false` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

In the worst case, we visit every cell and perform a DFS from each unvisited cell.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is proportional to the size of the grid due to the visited array and the DFS stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/detect-cycles-in-2d-grid/description/)

---
{{< youtube eQvsVEt_j8M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
