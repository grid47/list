
+++
authors = ["grid47"]
title = "Leetcode 2658: Maximum Number of Fish in a Grid"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2658: Maximum Number of Fish in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qn2ABHbRNnQ"
youtube_upload_date="2023-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qn2ABHbRNnQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        this->grid = grid;
        int mx = 0;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != 0) {
                mx = max(mx, dfs(i, j));
            }
        return mx;
    }
    
    int dfs(int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        
        ans += dfs(i + 1, j);
        ans += dfs(i - 1, j);
        ans += dfs(i, j + 1);
        ans += dfs(i, j - 1);
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the maximum amount of fish that can be collected from any connected group of cells in a given grid. The grid is a 2D array where each cell contains an integer, which represents the number of fish in that cell. A connected group of cells is defined as those cells that are adjacent either horizontally or vertically. We need to return the maximum number of fish that can be collected by any such connected group.

### Approach

To solve this problem, we can approach it as a **Depth-First Search (DFS)** problem. Each cell in the grid can be viewed as a node, and the problem boils down to finding the largest connected component in the grid. Since we are interested in the maximum number of fish in any connected component, we can perform a DFS on each unvisited cell containing fish. During the DFS traversal, we accumulate the number of fish from all cells in that component and keep track of the maximum value found.

**Key Insights**:
1. **DFS Traversal**: Start from each unvisited cell that contains fish, and use DFS to explore all connected cells that contain fish.
2. **Grid Constraints**: Ensure that the DFS stays within the bounds of the grid and only visits cells that have fish.
3. **Maximization**: Keep track of the largest sum of fish encountered during any DFS traversal.

### Code Breakdown (Step by Step)

```cpp
int m, n;
vector<vector<int>> grid;
```
- **Line 1**: Declare two variables `m` and `n` to store the number of rows and columns of the grid, respectively.
- **Line 2**: Declare a 2D vector `grid` to hold the grid of fish, where each element represents the number of fish at that cell.

```cpp
int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    this->grid = grid;
    int mx = 0;
```
- **Line 4-6**: The `findMaxFish` function is the main driver of the algorithm. It initializes `m` and `n` to represent the grid dimensions. We also store the grid passed as an argument in the class member variable `grid`. The variable `mx` is initialized to `0`, which will store the maximum number of fish found in any connected group.
  
```cpp
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != 0) {
                mx = max(mx, dfs(i, j));
            }
    return mx;
}
```
- **Line 7-11**: The double `for` loop iterates over each cell in the grid. If a cell contains fish (i.e., `grid[i][j] != 0`), we perform a DFS starting from that cell.
  - The DFS function `dfs(i, j)` explores all connected cells and returns the total number of fish in that connected component.
  - The `max` function ensures that `mx` always holds the maximum value of fish collected from any connected component.
- **Line 12**: Once all the cells are processed, return `mx`, which contains the maximum number of fish from any connected component.

```cpp
int dfs(int i, int j) {
    if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
```
- **Line 14-15**: The `dfs` function performs a depth-first traversal starting from the cell at position `(i, j)`. First, we check whether the cell is out of bounds or contains no fish (`grid[i][j] == 0`). If so, return 0 to terminate the DFS for that branch.
  
```cpp
    int ans = grid[i][j];
    grid[i][j] = 0;
```
- **Line 16-17**: If the current cell contains fish, we store the number of fish in `ans` and mark the cell as visited by setting `grid[i][j] = 0` to avoid revisiting the same cell.
  
```cpp
    ans += dfs(i + 1, j);
    ans += dfs(i - 1, j);
    ans += dfs(i, j + 1);
    ans += dfs(i, j - 1);
    
    return ans;
}
```
- **Line 18-21**: We recursively call `dfs` for all four possible directions (down, up, right, left) from the current cell. The results are added to `ans`, accumulating the number of fish in all connected cells.
- **Line 22**: Once all connected cells have been visited, return `ans`, which now contains the total number of fish in the connected component.

### Complexity

#### Time Complexity:
- **DFS Complexity**: Each cell in the grid is visited at most once by the DFS, and each DFS operation takes constant time to process each cell (for marking it as visited and checking its neighbors). Therefore, the time complexity of the DFS is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the grid.
- **Overall Complexity**: The algorithm runs a DFS for every cell that contains fish. Since each cell is visited only once, the overall time complexity is **O(m * n)**.

#### Space Complexity:
- **Space for Grid**: The space required for storing the grid is **O(m * n)**.
- **Recursive Stack**: The depth of the recursive stack in the worst case can be **O(m * n)** if all the cells are connected in one large component.
- **Overall Space Complexity**: Therefore, the overall space complexity is **O(m * n)** due to the grid storage and the recursive stack.

### Conclusion

This solution effectively utilizes **Depth-First Search (DFS)** to explore all connected components in the grid and calculate the total number of fish in each connected group. By maintaining a maximum value of the fish count during the DFS traversals, we are able to find the largest connected group of cells containing fish.

The algorithm is efficient with a time complexity of **O(m * n)**, where `m` and `n` are the dimensions of the grid, making it suitable for reasonably sized grids. The space complexity is also **O(m * n)** due to the storage of the grid and the recursive call stack.

Overall, this approach is optimal for solving problems involving connected components in grids and can be easily adapted for similar scenarios where other types of objects or values need to be collected from a grid structure.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

---
{{< youtube qn2ABHbRNnQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
