
+++
authors = ["grid47"]
title = "Leetcode 1020: Number of Enclaves"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1020: Number of Enclaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BcrKHwawGb8"
youtube_upload_date="2023-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/BcrKHwawGb8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                if(grid[i][j] == 1)
                    dfs(grid, i, j);
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1) cnt++;
        
        return cnt;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}
---



### Problem Statement
The objective is to count the number of enclaves in a 2D grid, where an enclave is defined as a land cell (`1`) that is completely surrounded by water cells (`0`). The grid is represented as a binary matrix, where `1` represents land and `0` represents water. Land cells that are connected to the border of the grid are not considered enclaves. For example, in a grid where the border land cells are connected to other land cells, those cells do not count towards the enclave total.

### Approach
To solve the problem, we can utilize Depth-First Search (DFS) to mark all land cells that are connected to the borders. By doing this, we effectively identify and exclude any land cells that cannot be considered as enclaves. The steps to achieve this are as follows:
1. **Boundary Traversal**: Iterate through the grid and start a DFS from every land cell that is located on the border of the grid. This will mark all reachable land cells as non-enclave (by changing their value).
2. **Counting Remaining Land Cells**: After marking the non-enclave land cells, traverse the grid again to count the remaining land cells, which represent the enclaves.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The function `numEnclaves` is defined as a public member of the `Solution` class, which takes a reference to a 2D vector of integers (`grid`) as its parameter.

2. **Grid Dimensions**:
   - The dimensions of the grid are obtained using `m = grid.size()` and `n = grid[0].size()`, where `m` is the number of rows and `n` is the number of columns in the grid.

3. **Boundary DFS**:
   - A nested loop iterates through each cell in the grid. For cells located on the border (i.e., when `i == 0`, `j == 0`, `i == m - 1`, or `j == n - 1`), the algorithm checks if the cell contains land (`grid[i][j] == 1`).
   - If a border land cell is found, the `dfs` function is called to start marking the connected land cells.

4. **Counting Enclaves**:
   - After marking the border-connected land cells, another nested loop iterates through the grid to count the remaining land cells. A variable `cnt` is initialized to zero and is incremented for each land cell found in the grid.

5. **Return Statement**:
   - Finally, the function returns the count of the enclaves.

6. **DFS Function**:
   - The `dfs` function is a private helper function that performs the depth-first search to mark land cells.
   - The function checks boundary conditions to prevent out-of-bounds access. If the current cell is out of the grid's bounds or not a land cell (`grid[i][j] != 1`), the function returns.
   - If a land cell is found, it is marked as visited by changing its value to `2`.
   - The `dfs` function is then recursively called for the four adjacent cells (down, right, up, left) to continue marking connected land cells.

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \( O(m \times n) \), where \( m \) is the number of rows and \( n \) is the number of columns in the grid. In the worst case, we visit each cell once.
- **Space Complexity**: The space complexity is \( O(h) \), where \( h \) is the depth of the recursion stack used by the DFS. In the worst case (e.g., for a completely filled grid), the depth can be \( O(m \times n) \), but this is generally considered \( O(h) \) in practice, where \( h \) is the maximum possible recursion depth.

### Conclusion
The `numEnclaves` function effectively counts the number of enclaves in a given grid using a combination of depth-first search and systematic marking of cells. This approach ensures that we only consider land cells that are truly surrounded by water, providing an accurate count of enclaves.

This solution highlights the efficiency of using DFS to explore connected components in a grid, making it a valuable technique for similar problems in graph theory and matrix manipulation. By understanding this approach, one can apply similar methods to various grid-related challenges, such as island counting, pathfinding, and connectivity analysis.

In summary, the `numEnclaves` function is an elegant example of how to manage and manipulate 2D arrays in C++ using depth-first search techniques. It demonstrates a clear and logical approach to solving the problem while maintaining optimal performance. This method not only showcases the ability to tackle specific grid-related problems but also offers insights into broader algorithmic strategies that can be applied to more complex scenarios involving connectivity and traversal.

Overall, the function serves as a practical reference for anyone looking to understand how to count surrounded regions in a grid, making it a valuable addition to a programmer’s skill set. Its efficiency and clarity make it suitable for implementation in real-world applications, particularly in areas related to geographical mapping, network analysis, and spatial data representation.


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-enclaves/description/)

---
{{< youtube BcrKHwawGb8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
