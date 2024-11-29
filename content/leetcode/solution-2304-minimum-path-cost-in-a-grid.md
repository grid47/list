
+++
authors = ["grid47"]
title = "Leetcode 2304: Minimum Path Cost in a Grid"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2304: Minimum Path Cost in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v_a0S1Tjuxk"
youtube_upload_date="2022-06-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/v_a0S1Tjuxk/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). The move from cells in the last row can be ignored. Each possible move has a cost given by the moveCost matrix, where moveCost[i][j] represents the cost of moving from a cell with value i to a cell in column j of the next row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two matrices: grid and moveCost.
- **Example:** `grid = [[8, 2], [4, 7], [5, 9]]; moveCost = [[5, 4], [2, 6], [3, 5], [4, 2], [7, 8], [9, 1], [3, 2], [8, 9], [5, 6], [6, 7], [3, 2], [1, 4]]`
- **Constraints:**
	- 2 <= m, n <= 50
	- grid consists of distinct integers from 0 to m * n - 1.
	- moveCost.length == m * n
	- 1 <= moveCost[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost of a path from the first row to the last row.
- **Example:** `The output for the example grid = [[8, 2], [4, 7], [5, 9]] and moveCost = [[5, 4], [2, 6], [3, 5], [4, 2], [7, 8], [9, 1], [3, 2], [8, 9], [5, 6], [6, 7], [3, 2], [1, 4]] is 12.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum cost path that starts from any cell in the first row and ends at any cell in the last row.

- Start from each cell in the first row.
- For each cell, calculate the possible paths to all cells in the next row.
- Use dynamic programming (memoization) to store the minimum cost for each cell to avoid redundant calculations.
- Return the minimum cost path at the end.
{{< dots >}}
### Problem Assumptions ✅
- You can start from any cell in the first row and end at any cell in the last row.
- The moveCost matrix defines the cost of moving from each cell to the cells in the next row.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[8, 2], [4, 7], [5, 9]], moveCost = [[5, 4], [2, 6], [3, 5], [4, 2], [7, 8], [9, 1], [3, 2], [8, 9], [5, 6], [6, 7], [3, 2], [1, 4]]`  \
  **Explanation:** The minimum path cost is achieved by the path 8 -> 7 -> 9 with a total cost of 12.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use dynamic programming to compute the minimum cost of moving through the grid.

### Initial Thoughts 💭
- Each row has multiple cells to move to the next row.
- The move cost depends on the value of the current cell and the target cell in the next row.
- We can calculate the cost for each cell in the first row and find the minimum path recursively.
{{< dots >}}
### Edge Cases 🌐
- The grid or moveCost matrix may never be empty.
- The solution should efficiently handle large grid sizes, up to 50 x 50.
- When all costs in moveCost are equal, the solution may be more straightforward.
- Ensure that all constraints are met while calculating the path cost.
{{< dots >}}
## Code 💻
```cpp
int m, n;

vector<vector<int>> grid, cost, memo;

int dp(int x, int y) {
    
    if(x == m - 1) return grid[x][y];
    
    if(memo[x][y] != -1) return memo[x][y];
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
    ans = min(ans, dp(x + 1, i) + grid[x][y] + cost[grid[x][y]][i]);
    
    return memo[x][y] = ans;
    
}

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    this->grid = grid;
    this->cost = moveCost;
    m = grid.size();
    n = grid[0].size();
    
    memo.resize(m, vector<int>(n, -1));
    
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp(0, i));
    }
    return ans;
}
```

The function `minPathCost` computes the minimum path cost from the top row of a grid to the bottom row, considering a move cost matrix that defines the cost of moving from one cell to another. The helper function `dp` is used for dynamic programming to store and reuse previously computed results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int m, n;
	```
	Declare two integer variables `m` and `n` to store the dimensions of the grid (number of rows and columns).

2. **Grid Initialization**
	```cpp
	vector<vector<int>> grid, cost, memo;
	```
	Declare 2D vectors `grid`, `cost`, and `memo`. `grid` stores the grid of values, `cost` stores the move cost for transitions between grid cells, and `memo` stores the results of subproblems for memoization in dynamic programming.

3. **Function Declaration**
	```cpp
	int dp(int x, int y) {
	```
	Declare the `dp` function that takes two arguments, `x` and `y`, representing the current row and column in the grid. This function calculates the minimum cost from the current cell to the bottom row.

4. **Base Case**
	```cpp
	    if(x == m - 1) return grid[x][y];
	```
	The base case for the recursion. If the current cell is in the last row, return the value of the cell itself since there are no more rows to traverse.

5. **Memoization Check**
	```cpp
	    if(memo[x][y] != -1) return memo[x][y];
	```
	Check if the result for the current cell `(x, y)` has already been computed. If so, return the stored result to avoid redundant calculations.

6. **Initialization**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize `ans` to `INT_MAX`, which will hold the minimum path cost. This variable is updated during the traversal.

7. **Loop Through Columns**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through each column `i` in the next row to find the minimum path cost from the current cell `(x, y)` to the bottom row.

8. **Recursive Call**
	```cpp
	    ans = min(ans, dp(x + 1, i) + grid[x][y] + cost[grid[x][y]][i]);
	```
	For each column `i`, recursively call `dp` for the next row `(x + 1, i)`. Add the cost of the current cell `grid[x][y]` and the move cost from `grid[x][y]` to `i` as given by the `cost` matrix. Update `ans` with the minimum cost found.

9. **Memoization**
	```cpp
	    return memo[x][y] = ans;
	```
	Memoize the result by storing the computed value of `ans` for the current cell `(x, y)` and return it.

10. **Main Function Declaration**
	```cpp
	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
	```
	Declare the `minPathCost` function, which takes two 2D vectors: `grid` representing the grid values and `moveCost` representing the move costs between cells.

11. **Grid Initialization**
	```cpp
	    this->grid = grid;
	```
	Initialize the class member `grid` with the input grid.

12. **Cost Initialization**
	```cpp
	    this->cost = moveCost;
	```
	Initialize the class member `cost` with the input move cost matrix.

13. **Grid Dimensions**
	```cpp
	    m = grid.size();
	```
	Set `m` to the number of rows in the grid.

14. **Grid Dimensions**
	```cpp
	    n = grid[0].size();
	```
	Set `n` to the number of columns in the grid.

15. **Memo Initialization**
	```cpp
	    memo.resize(m, vector<int>(n, -1));
	```
	Resize the `memo` vector to store results for all cells in the grid. Initially, all values are set to `-1` to indicate that no results have been computed yet.

16. **Initialize Result**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize `ans` to `INT_MAX`, which will hold the minimum path cost found during the traversal.

17. **Loop Through Columns**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loop through each column `i` in the first row to start the path traversal.

18. **Compute Minimum Cost**
	```cpp
	        ans = min(ans, dp(0, i));
	```
	For each column `i`, call `dp(0, i)` to find the minimum path cost starting from the first row. Update `ans` with the minimum value.

19. **Return Result**
	```cpp
	    return ans;
	```
	Return the minimum path cost stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n * n)
- **Worst Case:** O(m * n * n)

In the worst case, for each cell, we calculate the minimum cost for all possible moves to the next row.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We need space to store the memoization table, which is of size m x n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/)

---
{{< youtube v_a0S1Tjuxk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
