
+++
authors = ["grid47"]
title = "Leetcode 959: Regions Cut By Slashes"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 959: Regions Cut By Slashes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "j8KrBYIxHK8"
youtube_upload_date="2024-08-10"
youtube_thumbnail="https://i.ytimg.com/vi/j8KrBYIxHK8/maxresdefault.jpg"
comments = true
+++



---
You are given an n x n grid where each cell contains one of the following characters: '/', '\', or ' '. These characters divide the grid into different regions. Your task is to determine how many distinct regions the grid is divided into.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of strings representing the n x n grid, where each string corresponds to a row in the grid. Each character in the grid can be '/', '\', or ' '.
- **Example:** `Input: grid = [" /", "\ "]`
- **Constraints:**
	- 1 <= n <= 30
	- grid[i][j] is either '/', '\', or ' '.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of distinct regions formed by the characters in the grid.
- **Example:** `Output: 2`
- **Constraints:**
	- The function should return a non-negative integer representing the number of regions.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of distinct regions formed by '/' and '\' characters in the grid, with the characters dividing the grid into different regions.

- 1. Convert the grid into a larger grid where each cell in the original grid becomes a 3x3 subgrid.
- 2. Mark regions in the larger grid based on the '/' and '\' characters.
- 3. Use depth-first search (DFS) to count the number of distinct regions by traversing the grid and marking cells that are part of the same region.
{{< dots >}}
### Problem Assumptions ✅
- The grid is a valid n x n matrix with characters '/', '\', and ' '.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [" /", "\ "]`  \
  **Explanation:** In this case, the grid is divided into two distinct regions, one formed by the '/' and the other formed by the '\'.

- **Input:** `Input: grid = [" /", "  "]`  \
  **Explanation:** Here, the grid is divided into one region formed by the '/' character, and the second row is empty space.

- **Input:** `Input: grid = ["/\\", "\/ "]`  \
  **Explanation:** In this case, the grid is divided into five distinct regions due to the positioning of the '\' and '/' characters.

{{< dots >}}
## Approach 🚀
The approach involves transforming the grid into a 3x3 matrix for each original grid cell, then counting the number of connected regions using depth-first search (DFS).

### Initial Thoughts 💭
- Each cell in the grid can contribute to a new region or be part of an existing region depending on its connections with neighboring cells.
- By expanding each cell into a 3x3 subgrid, we can simplify the problem of region counting by treating connected components as parts of the same region.
{{< dots >}}
### Edge Cases 🌐
- The grid will never be empty as per the constraints.
- For larger grids, the solution must efficiently handle grids with dimensions up to 30x30.
- Consider grids with no '/' or '\' characters, where all cells are empty space.
- The grid will always be a square of size n x n with 1 <= n <= 30.
{{< dots >}}
## Code 💻
```cpp
int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '/') {
                g[i * 3 + 2][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3][j * 3 + 2] = 1;
            } else if(grid[i][j] == '\\') {
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
    int reg = 0;
    for(int i = 0; i < n * 3; i++) {
        for(int j = 0; j < n * 3; j++) {
            reg += dfs(g, i, j) ? 1 : 0;
        }
    }
    return reg;
}

int dfs(vector<vector<int>> &g, int i, int j) {
    if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0) {
        return 0;
    }
    g[i][j] = 1;
    return 1 + dfs(g, i + 1, j) + dfs(g, i - 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
}
```

This function determines the number of regions formed by slashes and backslashes in a grid. It expands the grid, performs depth-first search (DFS) to identify distinct regions, and counts them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int regionsBySlashes(vector<string>& grid) {
	```
	Declares the function that computes the number of regions formed by slashes in a given grid.

2. **Variable Initialization**
	```cpp
	    int n = grid.size();
	```
	Initializes the variable `n` with the size of the grid.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
	```
	Expands the grid by a factor of 3 to better represent slashes and backslashes.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Outer loop to iterate over rows of the grid.

5. **Inner Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Inner loop to iterate over columns of the grid.

6. **Slash Condition**
	```cpp
	            if(grid[i][j] == '/') {
	```
	Checks if the current cell contains a forward slash and marks corresponding positions in the expanded grid.

7. **Mark Grid for Slash**
	```cpp
	                g[i * 3 + 2][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3][j * 3 + 2] = 1;
	```
	Marks the positions of the forward slash in the expanded grid.

8. **Backslash Condition**
	```cpp
	            } else if(grid[i][j] == '\\') {
	```
	Checks if the current cell contains a backslash and marks corresponding positions in the expanded grid.

9. **Mark Grid for Backslash**
	```cpp
	                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
	```
	Marks the positions of the backslash in the expanded grid.

10. **Region Counter**
	```cpp
	    int reg = 0;
	```
	Initializes a counter for the number of distinct regions.

11. **Outer Loop for DFS**
	```cpp
	    for(int i = 0; i < n * 3; i++) {
	```
	Outer loop to iterate over rows of the expanded grid for DFS.

12. **Inner Loop for DFS**
	```cpp
	        for(int j = 0; j < n * 3; j++) {
	```
	Inner loop to iterate over columns of the expanded grid for DFS.

13. **Region Identification**
	```cpp
	            reg += dfs(g, i, j) ? 1 : 0;
	```
	Performs DFS to identify and count a new region if it exists.

14. **Return Statement**
	```cpp
	    return reg;
	```
	Returns the total number of regions identified in the grid.

15. **DFS Function Declaration**
	```cpp
	int dfs(vector<vector<int>> &g, int i, int j) {
	```
	Declares the depth-first search (DFS) helper function.

16. **Base Condition**
	```cpp
	    if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0) {
	```
	Checks if the current cell is out of bounds or already visited.

17. **Base Condition Return**
	```cpp
	        return 0; }
	```
	Returns 0 if the base condition is met.

18. **Mark Cell as Visited**
	```cpp
	    g[i][j] = 1;
	```
	Marks the current cell as visited in the grid.

19. **Recursive DFS Calls**
	```cpp
	    return 1 + dfs(g, i + 1, j) + dfs(g, i - 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
	```
	Recursively explores all neighboring cells to calculate the region size.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In all cases, the time complexity is O(n^2) because we need to explore every cell in the grid at least once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the storage of the larger grid for processing and the space used by the depth-first search stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/regions-cut-by-slashes/description/)

---
{{< youtube j8KrBYIxHK8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
