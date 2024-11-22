
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are tasked with determining the maximum number of moves in a grid starting from the leftmost column to the rightmost column, following specific movement rules. Each element in the grid represents a value, and from any cell, we are allowed to move to one of the following cells in the next column:
- Up-right diagonal (to the cell in the row above and the next column),
- Right (to the cell in the same row but the next column),
- Down-right diagonal (to the cell in the row below and the next column).

The goal is to find the maximum number of moves we can make by starting from any cell in the first column and ending in any cell in the last column, while only moving to a cell with a strictly greater value than the current one.

### Approach

This problem can be solved efficiently using Depth-First Search (DFS) combined with memoization. The basic idea is to explore all possible paths from each cell in the first column to the last column while respecting the constraints (i.e., moving only to cells with strictly greater values).

The DFS algorithm will:
1. Start at each cell in the first column.
2. Explore all three possible directions (up-right, right, down-right) to move to the next column, provided that the value of the next cell is strictly greater than the current cell's value.
3. Use memoization to store the results of subproblems (i.e., the maximum number of moves from each cell), preventing redundant calculations.

### Code Breakdown (Step by Step)

#### Step 1: Initial Setup

```cpp
int m, n;
vector<vector<int>> grid, mem;
```

- `m` and `n` represent the number of rows and columns of the grid, respectively.
- `grid` is the input 2D matrix representing the grid.
- `mem` is a 2D vector that will store the results of subproblems, where `mem[i][j]` stores the maximum number of moves starting from the cell `(i, j)`.

#### Step 2: Define the DFS Function

```cpp
int dfs(int p, int q) {
    if(mem[p][q] != -1) return mem[p][q];
    int ans = 0;
    if(p - 1 >= 0 && q + 1 < n && grid[p - 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p - 1, q + 1));
    if(p < m && q + 1 < n && grid[p][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p, q + 1));
    if(p + 1 < m && q + 1 < n && grid[p + 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p + 1, q + 1));
    return mem[p][q] = ans;
}
```

- The `dfs` function computes the maximum number of moves starting from a given cell `(p, q)` in the grid.
- The base case for the DFS is when the result has already been computed and stored in `mem[p][q]`. If `mem[p][q]` is not `-1`, it returns the stored value.
- The function recursively checks the three possible directions (up-right, right, down-right) and updates `ans` with the maximum number of moves found. If a valid move is found (i.e., moving to a cell with a strictly greater value), it recursively calls `dfs` for the next cell in that direction.
- Finally, the result is memoized in `mem[p][q]` to avoid recomputation in future calls.

#### Step 3: Main Function to Calculate the Maximum Moves

```cpp
int maxMoves(vector<vector<int>>& grid) {
    this->grid = grid;
    m = grid.size();
    n = grid[0].size();

    mem.resize(m, vector<int>(n, -1)); // Initialize memoization table with -1
    int ans = 0;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dfs(i, 0)); // Start DFS from each cell in the first column
    }
    return ans;
}
```

- The function `maxMoves` is the main function that calculates the result.
- The `grid` is passed as an argument, and `m` and `n` are initialized to the number of rows and columns of the grid, respectively.
- The memoization table `mem` is initialized with `-1`, indicating that no cell has been processed yet.
- A variable `ans` is used to store the maximum number of moves found across all starting points in the first column.
- The `for` loop iterates over all the cells in the first column (`i = 0` to `i = m-1`), and for each cell, the `dfs` function is called to compute the maximum number of moves starting from that cell.
- The final result is returned, which is the maximum number of moves starting from any cell in the first column.

### Complexity

#### Time Complexity

- The time complexity is `O(m * n)` where `m` is the number of rows and `n` is the number of columns.
- The `dfs` function is called once for each cell in the grid, and each cell is processed at most once due to memoization. Therefore, the total number of calls to `dfs` is proportional to the number of cells in the grid (`m * n`).

#### Space Complexity

- The space complexity is `O(m * n)` due to the memoization table `mem` that stores the results of the subproblems.
- Additionally, the space complexity includes the space required by the call stack for the DFS recursion, which is at most `O(m * n)` in the worst case (when exploring the entire grid).

### Conclusion

This solution leverages depth-first search (DFS) combined with memoization to efficiently compute the maximum number of moves from any starting cell in the first column to the last column of the grid. By memoizing the results of subproblems, we ensure that each cell is processed only once, making the solution highly efficient with a time complexity of `O(m * n)`.

The problem-solving approach effectively handles the constraints and ensures that we explore all valid paths while adhering to the movement rules of the grid. This solution is optimal for grids of moderate size and efficiently computes the desired result.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/)

---
{{< youtube MQQZiN9CnDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
