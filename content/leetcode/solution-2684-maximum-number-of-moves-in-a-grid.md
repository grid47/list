
+++
authors = ["grid47"]
title = "Leetcode 2684: Maximum Number of Moves in a Grid"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2684: Maximum Number of Moves in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MQQZiN9CnDk"
youtube_upload_date="2023-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/MQQZiN9CnDk/maxresdefault.jpg"
comments = true
+++



---
You are given a matrix `grid` of size `m x n` filled with positive integers. Starting from any cell in the first column, you can move to any of the cells on the next column (right) that are strictly greater than the value of the current cell. The possible directions you can move to are: the cell directly to the right, the cell diagonally to the top-right, or the cell diagonally to the bottom-right. Your task is to return the maximum number of moves that you can perform by starting at any cell in the first column.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix `grid` of size `m x n` where each value is a positive integer. You need to determine the maximum number of valid moves you can make by starting from any cell in the first column and moving in the allowed directions.
- **Example:** `Input: grid = [[1, 3, 2], [4, 2, 6], [3, 5, 7]]`
- **Constraints:**
	- 2 <= m, n <= 1000
	- 4 <= m * n <= 100000
	- 1 <= grid[i][j] <= 106

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of moves that can be made from the first column.
- **Example:** `Output: 3`
- **Constraints:**
	- The output will be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum number of valid moves that can be made starting from any cell in the first column and traversing according to the specified movement rules.

- Step 1: Start from each cell in the first column.
- Step 2: For each cell, recursively explore the possible moves (right, top-right, bottom-right) and compute the maximum number of valid moves.
- Step 3: Use memoization to store the results of subproblems to avoid redundant calculations.
- Step 4: Return the maximum number of moves that can be made from the first column.
{{< dots >}}
### Problem Assumptions ✅
- You can always make valid moves if the conditions are met.
- The grid is always valid and follows the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]`  \
  **Explanation:** We can start at the cell (0, 0) and make the following moves: (0, 0) -> (0, 1) -> (1, 2) -> (2, 3). The maximum number of moves is 3.

- **Input:** `Input: grid = [[3, 2, 4], [2, 1, 9], [1, 1, 7]]`  \
  **Explanation:** No valid moves can be made as there is no cell in the next column that is strictly greater than the current cell. Thus, the maximum number of moves is 0.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use dynamic programming and memoization to efficiently calculate the maximum number of moves that can be made from any starting cell.

### Initial Thoughts 💭
- We need to consider every cell in the first column as a potential starting point.
- The problem has overlapping subproblems, so we can use memoization to avoid redundant computations.
- A depth-first search (DFS) approach with memoization is suitable for this problem.
{{< dots >}}
### Edge Cases 🌐
- The input grid will never be empty as per the constraints.
- For larger grids, the algorithm should efficiently compute the result within time limits.
- The grid may have cells with the same values, in which case no valid move is possible from that cell.
- Ensure the solution handles both small and large grids efficiently.
{{< dots >}}
## Code 💻
```cpp
int m, n;
vector<vector<int>> grid, mem;

int dfs(int p, int q) {
    
    if(mem[p][q] != -1) return mem[p][q];
    int ans = 0;
    if(p - 1>= 0 && q + 1 < n && grid[p - 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p - 1, q + 1));
    if(p     < m && q + 1 < n && grid[p][q + 1]     > grid[p][q]) ans = max(ans, 1 + dfs(p    , q + 1));
    if(p + 1 < m && q + 1 < n && grid[p + 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p + 1, q + 1));

    return mem[p][q] = ans;
}

int maxMoves(vector<vector<int>>& grid) {
    this->grid = grid;
    m = grid.size();
    n = grid[0].size();

    mem.resize(m, vector<int>(n, -1));
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dfs(i, 0));
    }
    return ans;
}
```

The 'maxMoves' function computes the maximum number of valid moves possible on a grid by applying a depth-first search (DFS) from each position in the first column, using memoization to store results for already computed positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int m, n;
	```
	Declare two integers, 'm' and 'n', to store the dimensions of the grid.

2. **Variable Declaration**
	```cpp
	vector<vector<int>> grid, mem;
	```
	Declare two 2D vectors: 'grid' to represent the grid of values and 'mem' to store the memoization results for DFS.

3. **Function Definition**
	```cpp
	int dfs(int p, int q) {
	```
	Define the recursive function 'dfs' which calculates the maximum valid moves starting from position (p, q) using memoization.

4. **Base Case Check**
	```cpp
	    if(mem[p][q] != -1) return mem[p][q];
	```
	Check if the value for position (p, q) has already been computed (i.e., if it's not -1). If so, return the stored value.

5. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize 'ans' to 0, which will store the maximum number of moves from the current position.

6. **Recursive DFS Call**
	```cpp
	    if(p - 1>= 0 && q + 1 < n && grid[p - 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p - 1, q + 1));
	```
	Perform a DFS search to the upper-right neighboring cell if it exists and the value is greater than the current cell. Update 'ans' with the maximum result from the recursive call.

7. **Recursive DFS Call**
	```cpp
	    if(p     < m && q + 1 < n && grid[p][q + 1]     > grid[p][q]) ans = max(ans, 1 + dfs(p    , q + 1));
	```
	Perform a DFS search to the right neighboring cell if it exists and the value is greater than the current cell.

8. **Recursive DFS Call**
	```cpp
	    if(p + 1 < m && q + 1 < n && grid[p + 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p + 1, q + 1));
	```
	Perform a DFS search to the lower-right neighboring cell if it exists and the value is greater than the current cell.

9. **Memoization and Return**
	```cpp
	    return mem[p][q] = ans;
	```
	Store the computed value of 'ans' for position (p, q) in the memoization table and return the result.

10. **Function Definition**
	```cpp
	int maxMoves(vector<vector<int>>& grid) {
	```
	Define the function 'maxMoves' which computes the maximum number of valid moves on the grid by calling the DFS function from each starting position in the first column.

11. **Grid Assignment**
	```cpp
	    this->grid = grid;
	```
	Assign the input grid to the member variable 'grid'.

12. **Grid Dimensions**
	```cpp
	    m = grid.size();
	```
	Set 'm' to the number of rows in the grid.

13. **Grid Dimensions**
	```cpp
	    n = grid[0].size();
	```
	Set 'n' to the number of columns in the grid.

14. **Memory Allocation**
	```cpp
	    mem.resize(m, vector<int>(n, -1));
	```
	Resize the memoization table 'mem' to match the grid dimensions and initialize all values to -1.

15. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize 'ans' to store the maximum number of moves found during the DFS traversal.

16. **Loop**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Loop through all rows of the grid to perform DFS starting from each element in the first column.

17. **DFS Call**
	```cpp
	        ans = max(ans, dfs(i, 0));
	```
	For each row, call 'dfs' starting from the element at (i, 0) and update 'ans' with the maximum value returned.

18. **Return**
	```cpp
	    return ans;
	```
	Return the maximum number of valid moves found after completing all DFS calls.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The solution requires visiting each cell and calculating the maximum number of moves from that cell, resulting in linear time complexity relative to the number of cells in the grid.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the memoization table storing the results for each cell.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/)

---
{{< youtube MQQZiN9CnDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
