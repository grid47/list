
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
                reg += dfs(g, i, j)? 1: 0;
            }
        }
        return reg;
    }
    
    int dfs(vector<vector<int>> &g, int i, int j) {
        
        if ( min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0) {
            return 0; }
        
        g[i][j] = 1;
        
        return 1 + dfs(g, i + 1, j) + dfs(g, i - 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
        
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves calculating the number of **regions** formed by a grid of slashes and backslashes. The grid consists of characters `'/'` and `'\\'`, and we need to determine how many regions are created by these slashes when they divide the grid into smaller sub-regions. For instance, the slashes divide each cell into smaller triangles, and these cells can combine to form regions that are either connected or separated by the slashes.

The goal is to return the total number of **distinct regions** formed by the slashes, where regions are defined as groups of connected empty spaces.

### Approach

To solve this problem, we will use the following approach:

1. **Transform the grid**: Each cell in the grid can be viewed as a 3x3 block of smaller cells, where slashes divide the block into multiple sub-cells. This transformation allows us to work with smaller units and manage the connections between them.

2. **Graph Representation**: We represent the entire grid as a larger grid where each cell is divided into a 3x3 sub-grid. The task becomes a problem of counting the connected components in this transformed grid. We will use **Depth First Search (DFS)** to explore all connected regions in this larger grid.

3. **DFS Traversal**: By using DFS, we explore all connected empty spaces (cells with value 0) in the grid. Each time we encounter a new empty space that has not been visited, we initiate a DFS search, marking all connected cells as visited. Each new DFS invocation indicates the discovery of a new region.

4. **Counting Regions**: The number of times DFS is initiated corresponds to the number of distinct regions. We count these DFS invocations to determine the total number of regions.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();  // Get the size of the grid (number of rows/columns)
        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));  // Create a grid of size 3*n x 3*n to represent sub-cells
```

1. **Initialize the grid**: 
   - The input grid is of size `n x n`. To transform it into a graph where each cell is divided into 3x3 sub-cells, we create a new grid `g` of size `3*n x 3*n`. Each element of the grid `g` is initialized to 0 (indicating an empty space).

```cpp
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '/') {
                    // If the cell contains a '/', mark the appropriate cells as occupied
                    g[i * 3 + 2][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3][j * 3 + 2] = 1;
                } else if(grid[i][j] == '\\') {
                    // If the cell contains a '\\', mark the appropriate cells as occupied
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
```

2. **Marking the grid**: 
   - We iterate through each cell of the input grid. For each cell that contains a slash (`'/'` or `'\\'`), we mark the appropriate sub-cells in the larger grid `g` as occupied (with `1`). For a `/`, the three cells it divides in the sub-grid are marked, and similarly, for a `\\`, its corresponding sub-cells are marked.
   
```cpp
        int reg = 0;  // Initialize a counter for the regions
        for(int i = 0; i < n * 3; i++) {
            for(int j = 0; j < n * 3; j++) {
                reg += dfs(g, i, j)? 1: 0;  // For each cell, if DFS finds a new region, increment the count
            }
        }
        return reg;  // Return the total number of regions
    }
```

3. **Counting Regions**:
   - We initialize a variable `reg` to count the number of regions.
   - We iterate through each cell in the larger grid (`g`). If the cell is an empty space (i.e., its value is `0`), we start a DFS search to explore the connected region. Each successful DFS search indicates the discovery of a new region, so we increment the `reg` counter.
   
```cpp
    int dfs(vector<vector<int>> &g, int i, int j) {
        if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0) {
            return 0;  // If the cell is out of bounds or already visited, return 0
        }

        g[i][j] = 1;  // Mark the cell as visited
        
        // Perform DFS in all four directions: up, down, left, right
        return 1 + dfs(g, i + 1, j) + dfs(g, i - 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
    }
};
```

4. **DFS Function**:
   - The `dfs` function is a standard depth-first search. It starts from a given cell `(i, j)` and explores all connected empty spaces (cells with value `0`). 
   - It first checks if the current cell is out of bounds or has already been visited (i.e., its value is not `0`).
   - If the cell is valid, we mark it as visited by setting `g[i][j] = 1` and recursively call DFS on the neighboring cells (up, down, left, and right).
   - Each DFS invocation returns the number of connected empty cells, but the actual result isn't used because we are only interested in whether a region exists or not. Hence, DFS returns `1` for each valid region it discovers.

### Complexity

- **Time Complexity**: The time complexity of this solution is **O(n^2)**, where `n` is the size of the input grid. This is because:
  - We traverse every cell in the grid once, which takes `O(n^2)` time.
  - For each cell, we may perform a DFS, but each cell is visited at most once during DFS. The DFS explores at most `O(9)` cells (since each cell in the grid is represented by a 3x3 sub-grid), so the complexity per cell is constant.
  
- **Space Complexity**: The space complexity is **O(n^2)** because the largest grid we construct (`g`) has a size of `3*n x 3*n`, which requires `O(n^2)` space. Additionally, the recursive stack used in DFS can go as deep as `O(n^2)` in the worst case (if all cells are connected).

### Conclusion

This solution efficiently calculates the number of regions formed by slashes in the grid using depth-first search. By transforming the grid into a larger representation and applying DFS, we can systematically explore all connected components and count the distinct regions. The approach guarantees that each cell is visited only once, ensuring optimal time and space complexity for solving this problem. This method is both easy to understand and implement, making it a robust solution for this type of problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/regions-cut-by-slashes/description/)

---
{{< youtube j8KrBYIxHK8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
