
+++
authors = ["grid47"]
title = "Leetcode 1219: Path with Maximum Gold"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1219: Path with Maximum Gold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I1wllM_pozY"
youtube_upload_date="2024-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/I1wllM_pozY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxGold = max(maxGold, findMax(grid, m, n, i, j));
        return maxGold;
    }
    
    int dir[5] = {0,1,0,-1,0};
    
    int findMax(vector<vector<int>> &grid, int m,int n, int r, int c) {
        if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
            return 0;
        int origin = grid[r][c];
        grid[r][c] = 0;
        int mx = 0;
        for(int i = 0; i < 4; i++)
            mx = max(mx, findMax(grid, m, n, r+dir[i], c+dir[i+1]));
        grid[r][c]=origin;
        return mx+origin;
    }
};
{{< /highlight >}}
---


### Problem Statement
The goal of the problem is to find the maximum amount of gold that can be collected from a grid. The grid is represented as a 2D vector where each cell can contain either gold (denoted by a positive integer) or be empty (denoted by `0`). You can start collecting gold from any cell that contains gold, and you can move in any of the four cardinal directions (up, down, left, right). The challenge lies in the fact that once you leave a cell (i.e., collect gold from it), you cannot return to it during the same path.

For example, given a grid like the following:

```
[[0,6,0],
 [5,8,7],
 [0,9,0]]
```

You would want to calculate the maximum gold you could collect by starting from any gold-containing cell and moving to adjacent cells without revisiting any cell.

### Approach
To solve the problem, we employ a depth-first search (DFS) strategy. The idea is to explore all possible paths starting from each cell containing gold and track the amount of gold collected along each path. The steps involved in the approach are:

1. **Initialize Variables**: Track the maximum gold found using a variable `maxGold`.
2. **Iterate Through Grid**: Loop through each cell in the grid and for each cell containing gold, invoke the `findMax` function to explore all possible paths and calculate the total gold collected.
3. **DFS Traversal**: The `findMax` function will recursively explore all four possible directions from the current cell, collect the gold, and backtrack to try different paths.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
```
- **Line 1-2**: Define the `Solution` class and the `getMaximumGold` method that takes a 2D vector `grid` as input.

```cpp
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
```
- **Lines 3-4**: Calculate the dimensions of the grid, `m` (rows) and `n` (columns), and initialize a variable `maxGold` to store the maximum gold collected.

```cpp
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxGold = max(maxGold, findMax(grid, m, n, i, j));
```
- **Lines 5-7**: Iterate through each cell in the grid. If a cell contains gold, call the `findMax` function to calculate the maximum gold collectible starting from that cell. Update `maxGold` accordingly.

```cpp
        return maxGold;
    }
```
- **Lines 8-9**: Return the maximum gold collected after checking all possible starting points.

```cpp
    int dir[5] = {0,1,0,-1,0};
```
- **Line 10**: Define a direction array `dir` to facilitate movement in the four cardinal directions (right, down, left, up).

```cpp
    int findMax(vector<vector<int>> &grid, int m, int n, int r, int c) {
```
- **Line 11**: Define the `findMax` function, which performs the DFS. This function takes the grid and the current position `(r, c)` as input parameters.

```cpp
        if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
            return 0;
```
- **Lines 12-13**: Check for boundary conditions. If the current position is out of bounds or if the cell is empty (contains `0`), return `0` as no gold can be collected from this path.

```cpp
        int origin = grid[r][c];
        grid[r][c] = 0;
```
- **Lines 14-15**: Store the amount of gold in the current cell `origin` and mark the cell as visited by setting its value to `0`.

```cpp
        int mx = 0;
        for(int i = 0; i < 4; i++)
            mx = max(mx, findMax(grid, m, n, r+dir[i], c+dir[i+1]));
```
- **Lines 16-19**: Initialize a variable `mx` to keep track of the maximum gold collectible from this cell. For each of the four possible directions, recursively call `findMax` to explore adjacent cells and update `mx`.

```cpp
        grid[r][c] = origin;
```
- **Line 20**: Backtrack by restoring the original value of the current cell after all paths have been explored. This is crucial to allow other paths to access this cell again.

```cpp
        return mx + origin;
    }
};
```
- **Line 21**: Return the total amount of gold collected from this path, which is the maximum found in the adjacent cells plus the gold from the current cell.

### Complexity
1. **Time Complexity**:
   - The time complexity of this solution is \(O(m \cdot n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the grid. In the worst case, we may visit every cell multiple times during the DFS, but each cell will only contribute to the result once due to backtracking.

2. **Space Complexity**:
   - The space complexity is \(O(m \cdot n)\) due to the recursion stack in the DFS. In the worst-case scenario, the depth of recursion could reach \(O(m \cdot n)\) when the grid is fully filled with gold.

### Conclusion
The `getMaximumGold` function effectively utilizes a depth-first search algorithm to explore all possible paths for collecting gold in a grid. By marking cells as visited and backtracking, it ensures that each path is calculated accurately without revisiting cells. This method demonstrates an efficient approach to solving pathfinding problems in grids, making it a valuable technique in competitive programming and algorithm design. Overall, the solution is both intuitive and efficient, providing a clear way to maximize gold collection in a structured environment.

[`Link to LeetCode Lab`](https://leetcode.com/problems/path-with-maximum-gold/description/)

---
{{< youtube I1wllM_pozY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
