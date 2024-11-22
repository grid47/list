
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
    
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the maximum product of values along a path from the top-left corner to the bottom-right corner of a grid. The grid can contain positive, negative, or zero values. The goal is to traverse from the starting cell (0, 0) to the target cell (m-1, n-1) while maximizing the product of the cell values along the path. If the maximum product is negative, the function should return -1. The path can only move right or down.

### Approach

To tackle this problem, we can use a depth-first search (DFS) strategy to explore all potential paths through the grid while keeping track of the cumulative product. The approach involves the following steps:

1. **Initialization**: Set up necessary variables including the dimensions of the grid, a memoization table to store intermediate results, and a modulo constant to ensure results fit within limits.

2. **DFS Function**: Create a recursive function that:
   - Takes the current position in the grid and the accumulated product as parameters.
   - Checks if the current position is the bottom-right corner. If so, it returns the product multiplied by the value of the current cell.
   - Handles the case where the cell value is zero, returning zero immediately since any product involving zero is zero.
   - Recursively explores possible moves to the right and down, updating the maximum product found along those paths.

3. **Handling Results**: After the DFS completes, check the final result. If the maximum product is negative, return -1; otherwise, return the maximum product modulo \(10^9 + 7\).

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the code:

```cpp
class Solution {
public:
    int m, n; // Dimensions of the grid
    vector<vector<int>> grid; // The input grid
    vector<vector<long long>> memo; // Memoization table
    int mod = (int) 1e9 + 7; // Modulo constant
    
    int maxProductPath(vector<vector<int>>& grid) {
```
- **Class Definition**: The `Solution` class defines the public members necessary for solving the problem. The members include the dimensions of the grid (`m`, `n`), the grid itself, a memoization table, and a modulo constant for returning results.

```cpp
        this->m = grid.size(); // Set number of rows
        this->n = grid[0].size(); // Set number of columns
        this->grid = grid; // Store the input grid
        
        memo.resize(m, vector<long long>(n, LLONG_MIN)); // Initialize memoization table with minimum values
        
        int ans = dfs(0, 0, 1) % mod; // Start DFS from the top-left corner with an initial product of 1
        
        return ans < 0? -1: ans; // Return -1 if product is negative, otherwise return the product
    }
```
- **Initialization**: The `maxProductPath` function initializes the dimensions and stores the grid. It sets up the memoization table to store results for each cell and starts the DFS from the top-left corner of the grid. The initial product is set to 1 because multiplying by 1 does not change the value.

```cpp
    long long dfs(int i, int j, long long val) {
```
- **DFS Function**: The `dfs` function is defined to take the current indices and the accumulated product value as parameters.

```cpp
        if(i == m - 1 && j == n - 1) return (val * grid[i][j]); // Check if reached the bottom-right corner
```
- **Base Case**: If the current position is the bottom-right corner, it multiplies the current accumulated product (`val`) by the value of the current cell and returns this result.

```cpp
        long long ans = LLONG_MIN; // Initialize the answer to a very low value
```
- **Answer Initialization**: The variable `ans` is initialized to the minimum possible value to ensure that any product found will be greater.

```cpp
        if(grid[i][j] == 0) return 0; // If current cell value is zero, return zero immediately
```
- **Zero Handling**: If the current cell's value is zero, the function returns zero because any product including zero is zero.

```cpp
        if(i + 1 < m) // Check if moving down is within bounds
            ans = max(ans, dfs(i + 1, j, val * grid[i][j])); // Move down

        if(j + 1 < n) // Check if moving right is within bounds
            ans = max(ans, dfs(i, j + 1, val * grid[i][j])); // Move right
```
- **Recursive Exploration**: The function checks if it can move down or right:
  - If moving down is valid, it recursively calls `dfs` for the cell below and updates `ans` with the maximum product found.
  - If moving right is valid, it does the same for the cell to the right.

```cpp
        return ans; // Return the maximum product found along this path
    }
};
```
- **Returning the Result**: The function returns the maximum product found from the current cell.

### Complexity

- **Time Complexity**: The time complexity of this approach is \(O(2^{m+n})\) in the worst case, where `m` is the number of rows and `n` is the number of columns in the grid. This is because the algorithm explores all possible paths from the top-left to the bottom-right corner.

- **Space Complexity**: The space complexity is \(O(m \times n)\) due to the memoization table storing results for each cell. Additionally, the call stack of the recursion may also consume space proportional to the depth of the recursion (which can be at most \(m+n\)).

### Conclusion

The approach effectively uses a recursive DFS to explore all paths through the grid while keeping track of the product of cell values. The key steps involve:

1. **Recursive Exploration**: The use of recursion allows a comprehensive search of all potential paths while accumulating the product.
2. **Edge Case Handling**: Immediate handling of zero values ensures that the algorithm avoids unnecessary calculations that would yield zero products.
3. **Final Result Processing**: The modulo operation ensures that the results stay within manageable limits as required by the problem constraints.

This method provides a clear and systematic way to tackle the problem of finding the maximum product path in a grid, balancing both clarity and efficiency. Further optimizations, such as memoization, could be explored to enhance performance in larger grids.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

---
{{< youtube zGDdmRr1YIQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
