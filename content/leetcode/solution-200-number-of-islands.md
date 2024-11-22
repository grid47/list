
+++
authors = ["grid47"]
title = "Leetcode 200: Number of Islands"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 200: Number of Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/200.webp"
youtube = "IeuyI_kZ5zI"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/IeuyI_kZ5zI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/200.webp" 
    alt="A map of glowing islands floating gently, with the number of islands appearing as a soft count."
    caption="Solution to LeetCode 200: Number of Islands Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '1') {
                cnt++;
                dfs(grid, i, j);
            }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}
---

### 🌊 Counting Islands in a 2D Grid (DFS Approach)

In this problem, we are tasked with counting the number of **distinct islands** in a given 2D grid. The grid consists of '1's (representing land) and '0's (representing water). An island is formed by connecting adjacent lands (horizontally or vertically). The goal is to return the number of distinct islands in the grid.

#### Example:
- **Input:**  
  ```cpp
  grid = [
      ['1', '1', '1', '1', '0'],
      ['1', '1', '0', '1', '0'],
      ['1', '1', '0', '0', '0'],
      ['0', '0', '0', '0', '0']
  ]
  ```
- **Output:** `1`  
  **Explanation:** The grid contains one island.

### 💡 Approach

The problem can be solved using a **Depth-First Search (DFS)** approach. DFS is ideal because it allows us to explore all connected land cells (i.e., all '1's connected horizontally or vertically) starting from any unvisited '1'. By marking each visited land cell as '0', we ensure that each island is counted only once.

#### Steps:
1. **Iterate through the grid:** Start by iterating over each cell in the grid. If we encounter a '1', it means we have found a new island.
  
2. **DFS Traversal:** Once we find a '1', we initiate a DFS search starting from that cell. During the DFS, we explore all connected land cells and mark them as visited (changing them to '0').

3. **Count Islands:** Each time we start a DFS search from an unvisited '1', it corresponds to discovering a new island. We increment the island count.

4. **Return the result:** After iterating through the entire grid, the island count will reflect the number of distinct islands in the grid.

### 🛠 Code Breakdown

#### Step 1: Initialize and Traverse the Grid
```cpp
int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int m = grid.size(), n = grid[0].size();
```
- `cnt` is used to keep track of the number of islands.
- `m` and `n` store the number of rows and columns in the grid, respectively.

#### Step 2: Iterate Over Each Cell in the Grid
```cpp
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '1') {
                cnt++;
                dfs(grid, i, j);
            }
```
- We use two nested loops to iterate through each cell in the grid.
- If a cell contains '1', it indicates a new island. We increment the island count (`cnt`) and initiate a DFS search to mark all connected land cells as visited.

#### Step 3: DFS Function
```cpp
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
```
- The DFS function explores the land cells that are connected to the starting point (i, j).
- **Base Case:** If the current cell is out of bounds or contains water ('0'), we return.
- **Mark as Visited:** We mark the current land cell ('1') as water ('0') to avoid revisiting it.
- **Recursion:** We then recursively explore the neighboring cells (down, right, up, and left).

#### Step 4: Return the Number of Islands
```cpp
    return cnt;
}
```
- After processing the entire grid, we return the number of islands found (`cnt`).

### 📊 Complexity Analysis

#### Time Complexity:
- **O(m * n):** In the worst case, the algorithm visits every cell in the grid once. Each DFS call processes a single land cell and marks it as visited. Since we visit every cell exactly once, the time complexity is O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid.

#### Space Complexity:
- **O(m * n):** The space complexity is mainly determined by the recursion stack in DFS. In the worst case, we may need to recurse through all the cells in the grid. Therefore, the space complexity is O(m * n). This could be improved to O(min(m, n)) if we use an iterative DFS or BFS approach instead of recursion.

### 🚀 Conclusion

This solution effectively counts the number of distinct islands in a 2D grid using a DFS approach. Here's a summary:

1. **DFS Traversal:** The DFS explores all connected '1's (land) starting from any unvisited '1', marking them as visited by changing them to '0'. This ensures each island is counted only once.
2. **Efficiency:** The solution runs in O(m * n) time and uses O(m * n) space due to the recursion stack.
3. **Space Optimization:** The recursive DFS could be optimized to an iterative approach, but the current recursive solution is simple and efficient for most practical cases.

Overall, this solution provides a clear and optimal method for counting islands in a grid, making it well-suited for handling large grids effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-islands/description/)

---
{{< youtube IeuyI_kZ5zI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
