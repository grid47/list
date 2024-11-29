
+++
authors = ["grid47"]
title = "Leetcode 1594: Maximum Non Negative Product in a Matrix"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1594: Maximum Non Negative Product in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zGDdmRr1YIQ"
youtube_upload_date="2020-09-20"
youtube_thumbnail="https://i.ytimg.com/vi/zGDdmRr1YIQ/maxresdefault.jpg"
comments = true
+++



---
You are given a m x n matrix grid. Starting at the top-left corner (0, 0), you can only move right or down. Your task is to find the path from the top-left to the bottom-right corner that results in the maximum non-negative product of the grid values along the path. If such a path results in a negative product, return -1. The product is calculated by multiplying all grid values visited along the path. You should return the maximum non-negative product modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix grid of size m x n where each element is an integer between -4 and 4, inclusive.
- **Example:** `Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]`
- **Constraints:**
	- 1 <= m, n <= 15
	- -4 <= grid[i][j] <= 4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum non-negative product modulo 10^9 + 7. If the maximum product is negative, return -1.
- **Example:** `Output: 8`
- **Constraints:**
	- The answer should be modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the path from the top-left to the bottom-right corner that results in the maximum non-negative product.

- 1. Use depth-first search (DFS) to explore all possible paths from (0, 0) to (m - 1, n - 1).
- 2. At each position, compute the product of the path visited so far and update the result if a higher non-negative product is found.
- 3. Use memoization to store intermediate results and avoid redundant calculations.
{{< dots >}}
### Problem Assumptions ✅
- The grid is not empty and has at least one element.
- You can only move right or down from any cell.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]`  \
  **Explanation:** The path that yields the maximum non-negative product is (1 -> 1 -> -2 -> -4 -> 1), resulting in a product of 8. Hence, the output is 8.

- **Input:** `Input: grid = [[1,3],[0,-4]]`  \
  **Explanation:** The path yielding the maximum non-negative product is (1 -> 0 -> -4), which results in a product of 0. Hence, the output is 0.

- **Input:** `Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]`  \
  **Explanation:** In this case, all possible paths result in a negative product. Therefore, the output is -1.

{{< dots >}}
## Approach 🚀
The approach uses depth-first search (DFS) to explore all possible paths from the top-left to the bottom-right of the grid, while tracking the product of the elements along the path. Memoization is used to store intermediate results and avoid redundant calculations.

### Initial Thoughts 💭
- We need to explore all possible paths, but it is computationally expensive to do so without memoization.
- Since the product may grow large or negative, we need to ensure we are working with modulo 10^9 + 7 to prevent overflow.
- DFS with memoization is an ideal choice because it allows us to efficiently explore paths while reducing repeated calculations.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty, return 0.
- The grid size is relatively small (maximum 15x15), but we should ensure the solution is efficient enough to handle the worst-case scenario.
- If all values in the grid are negative or zero, it may be impossible to find a non-negative product path.
- Ensure the solution works for all input grids within the given constraints, especially ensuring the result is modulo 10^9 + 7.
{{< dots >}}
## Code 💻
```cpp
int m, n;
vector<vector<int>> grid;
vector<vector<long long>> memo;
int mod = (int) 1e9 + 7;

int maxProductPath(vector<vector<int>>& grid) {
    
    this->m = grid.size();
    this->n = grid[0].size();
    this->grid = grid;
    
    memo.resize(m, vector<long long>(n, LLONG_MIN));
    
    int ans = dfs(0, 0, 1) % mod;
    
    return ans < 0? -1: ans;
    
}

long long dfs(int i, int j, long long val) {
    
    if(i == m - 1 && j == n - 1) return (val * grid[i][j]);

    // if(memo[i][j] != LLONG_MIN) return memo[i][j];
    long long ans = LLONG_MIN;
    
    if(grid[i][j] == 0) return 0;
    
    if(i + 1 < m)
    ans = max(ans, dfs(i + 1, j, val * grid[i][j]));

    if(j + 1 < n)            
    ans = max(ans, dfs(i, j + 1, val * grid[i][j]));
    
    // return memo[i][j] = ans;
    return ans;
}

```

The provided solution calculates the maximum product path in a grid where each cell contains an integer. The function `maxProductPath` utilizes Depth-First Search (DFS) to explore all possible paths and find the path with the highest product, while avoiding overflow or negative results. The recursive DFS function ensures that all possible movements (down or right) are explored to compute the maximum possible product.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int m, n;
	```
	These are the integer variables that store the number of rows (`m`) and columns (`n`) of the grid, respectively.

2. **Grid Initialization**
	```cpp
	vector<vector<int>> grid;
	```
	A 2D vector that represents the grid of integers which stores the values used for calculating the maximum product path.

3. **Memoization**
	```cpp
	vector<vector<long long>> memo;
	```
	A 2D vector used for memoization, which stores intermediate results to avoid recalculating values for already visited grid cells.

4. **Constant Definition**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	This defines a constant `mod` used to return the result modulo (10^9 + 7) to prevent overflow.

5. **Function Definition**
	```cpp
	int maxProductPath(vector<vector<int>>& grid) {
	```
	This is the main function where the grid is passed as an argument. It initializes the grid dimensions and calls the DFS function to find the maximum product path.

6. **Grid Initialization**
	```cpp
	this->m = grid.size();
	```
	Assigns the number of rows in the grid to the variable `m`.

7. **Grid Initialization**
	```cpp
	this->n = grid[0].size();
	```
	Assigns the number of columns in the grid to the variable `n`.

8. **Grid Assignment**
	```cpp
	this->grid = grid;
	```
	Assigns the input grid to the member variable `grid`.

9. **Memoization**
	```cpp
	memo.resize(m, vector<long long>(n, LLONG_MIN));
	```
	Resizes the memoization table `memo` to match the dimensions of the grid and initializes all cells to `LLONG_MIN` (a very small value).

10. **Recursive Function Call**
	```cpp
	int ans = dfs(0, 0, 1) % mod;
	```
	Calls the DFS function to explore the grid starting from the top-left corner (0,0), with an initial product value of 1.

11. **Return Statement**
	```cpp
	return ans < 0? -1: ans;
	```
	Returns the computed result. If the result is negative (meaning no valid path was found), it returns -1, otherwise, it returns the computed maximum product path modulo (10^9 + 7).

12. **Recursive Function Definition**
	```cpp
	long long dfs(int i, int j, long long val) {
	```
	Defines the DFS function that explores the grid recursively. It calculates the product of the path from position `(i, j)` to the bottom-right corner.

13. **Base Case**
	```cpp
	if(i == m - 1 && j == n - 1) return (val * grid[i][j]);
	```
	Base case for the DFS function. If the current position is the bottom-right corner of the grid, it returns the accumulated product.

14. **Variable Initialization**
	```cpp
	long long ans = LLONG_MIN;
	```
	Initializes the variable `ans` to the smallest possible value (`LLONG_MIN`) to ensure that the maximum value is found during the recursion.

15. **Edge Case Handling**
	```cpp
	if(grid[i][j] == 0) return 0;
	```
	If the current cell in the grid contains 0, the function immediately returns 0 as multiplying by 0 would lead to a product of 0.

16. **Recursive Exploration**
	```cpp
	if(i + 1 < m) ans = max(ans, dfs(i + 1, j, val * grid[i][j]));
	```
	Recursively explores the cell below the current one, updating the `ans` if a better product path is found.

17. **Recursive Exploration**
	```cpp
	if(j + 1 < n) ans = max(ans, dfs(i, j + 1, val * grid[i][j]));
	```
	Recursively explores the cell to the right of the current one, updating the `ans` if a better product path is found.

18. **Return Statement**
	```cpp
	return ans;
	```
	Returns the maximum product path found for the current cell `(i, j)`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n) - If the grid is very small or the solution is quickly found.
- **Average Case:** O(m * n) - On average, we explore all grid cells once due to memoization.
- **Worst Case:** O(m * n) - In the worst case, we need to explore all paths in the grid.

The time complexity is proportional to the size of the grid, i.e., O(m * n), since memoization ensures each cell is processed only once.

### Space Complexity 💾
- **Best Case:** O(m * n) - Space complexity remains the same even for small grids.
- **Worst Case:** O(m * n) - Space is required for the memoization table and the recursion stack.

The space complexity is proportional to the size of the grid, due to the memoization table and the recursive call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

---
{{< youtube zGDdmRr1YIQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
