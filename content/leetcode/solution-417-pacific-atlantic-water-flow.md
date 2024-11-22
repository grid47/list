
+++
authors = ["grid47"]
title = "Leetcode 417: Pacific Atlantic Water Flow"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 417: Pacific Atlantic Water Flow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/417.webp"
youtube = "1HDq998kmio"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1HDq998kmio/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/417.webp" 
    alt="A map with water flowing from both Pacific and Atlantic oceans, gently meeting at highlighted points."
    caption="Solution to LeetCode 417: Pacific Atlantic Water Flow Problem"
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        for(int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j);
            dfs(heights, atl, m -1, j);            
        }
        for(int j = 0; j < m; j++) {
            dfs(heights, pac, j, 0);
            dfs(heights, atl, j, n - 1);            
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(pac[i][j] && atl[i][j])
                ans.push_back({i, j});
        return ans;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j) {
        
        vis[i][j] = true;
        if(i > 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
            dfs(h, vis, i - 1, j);
        if(j > 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
            dfs(h, vis, i, j - 1);
        if(i < h.size() - 1 && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
            dfs(h, vis, i + 1, j);
        if(j < h[0].size() - 1 && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
            dfs(h, vis, i, j + 1);
        
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find all the coordinates in a given matrix of heights where water can flow to both the Pacific and Atlantic oceans. The matrix represents an elevation map where each cell contains the height of that point. Water can flow from a cell to its neighboring cell if the height of the neighboring cell is greater than or equal to the current cell's height. The task is to return all the coordinates where water can flow to both oceans. The Pacific Ocean touches the left and top borders, while the Atlantic Ocean touches the right and bottom borders.

### Approach

The approach to solving this problem uses depth-first search (DFS) and two separate DFS traversals: one for the Pacific Ocean and one for the Atlantic Ocean. The idea is to track which cells can flow into each ocean by starting from the borders corresponding to each ocean and using DFS to propagate possible water flows.

Here’s the step-by-step approach:

1. **Initial Setup**:
   - We have a grid `heights` with dimensions `m x n` representing the elevation of different cells.
   - We need to determine for each cell whether water can flow to the Pacific and/or Atlantic oceans.

2. **Water Flow Direction**:
   - Water can only flow to neighboring cells (up, down, left, or right) if the neighboring cell's height is greater than or equal to the current cell's height.
   - We will start from the borders of the matrix: the top and left borders for the Pacific Ocean, and the bottom and right borders for the Atlantic Ocean.

3. **DFS Traversal**:
   - We will use DFS to propagate possible water flows from the borders to the inner cells, marking cells that can flow to the corresponding ocean.
   - The DFS is initiated from all cells along the Pacific and Atlantic borders.

4. **Result Calculation**:
   - After running the DFS for both oceans, the final answer will consist of the coordinates of cells that can flow to both the Pacific and Atlantic oceans. These are the cells where both the corresponding matrices (one for Pacific and one for Atlantic) are marked `true`.

5. **Time Complexity**:
   - The DFS runs in `O(m * n)` time for each ocean, where `m` and `n` are the number of rows and columns in the matrix. Since we perform two DFS traversals, the time complexity is `O(2 * m * n)` or simply `O(m * n)`.

### Code Breakdown (Step by Step)

#### Step 1: Initializing Helper Data Structures

```cpp
int m = heights.size(), n = heights[0].size();
vector<vector<bool>> pac(m, vector<bool>(n, false));
vector<vector<bool>> atl(m, vector<bool>(n, false));
```

- We calculate the dimensions `m` and `n` of the matrix `heights`.
- We initialize two 2D boolean matrices, `pac` and `atl`, each of size `m x n`. These matrices will be used to track which cells can flow to the Pacific Ocean (`pac`) and the Atlantic Ocean (`atl`). All cells are initially marked as `false`.

#### Step 2: DFS for Pacific and Atlantic Ocean

```cpp
for(int j = 0; j < n; j++) {
    dfs(heights, pac, 0, j);
    dfs(heights, atl, m -1, j);            
}
for(int j = 0; j < m; j++) {
    dfs(heights, pac, j, 0);
    dfs(heights, atl, j, n - 1);            
}
```

- The outer loops iterate through the borders of the matrix. The Pacific Ocean touches the top row (`0, j`) and the left column (`j, 0`), so we initiate DFS from these cells to propagate possible water flow.
- Similarly, the Atlantic Ocean touches the bottom row (`m - 1, j`) and the right column (`j, n - 1`), so we initiate DFS from these cells for the Atlantic Ocean.

#### Step 3: DFS Function for Propagating Water Flow

```cpp
void dfs(vector<vector<int>>& h, vector<vector<bool>> &vis, int i, int j) {
    vis[i][j] = true;
    if(i > 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
        dfs(h, vis, i - 1, j);
    if(j > 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
        dfs(h, vis, i, j - 1);
    if(i < h.size() - 1 && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
        dfs(h, vis, i + 1, j);
    if(j < h[0].size() - 1 && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
        dfs(h, vis, i, j + 1);
}
```

- The DFS function is called for each cell. The `vis` matrix tracks the visited cells for the given ocean (`pac` or `atl`).
- At each cell `(i, j)`, we mark it as visited (`vis[i][j] = true`).
- The DFS continues to neighboring cells in the up, down, left, and right directions if the neighboring cell has a greater or equal height (`h[i - 1][j] >= h[i][j]` for up, and similarly for other directions).
- This recursive propagation ensures that all cells that can flow to the respective ocean (Pacific or Atlantic) are marked.

#### Step 4: Collecting the Result

```cpp
vector<vector<int>> ans;
for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(pac[i][j] && atl[i][j])
            ans.push_back({i, j});
return ans;
```

- After both DFS traversals are complete, we iterate through the matrix.
- For each cell `(i, j)`, if the cell can flow to both the Pacific (`pac[i][j] == true`) and Atlantic oceans (`atl[i][j] == true`), we add the cell coordinates to the result vector `ans`.
- Finally, we return the result vector `ans`, which contains all the coordinates where water can flow to both oceans.

### Complexity

#### Time Complexity:
- **DFS Complexity**: For each DFS traversal, we visit every cell once, making the time complexity for one DFS `O(m * n)`, where `m` and `n` are the number of rows and columns of the matrix.
- **Overall Complexity**: Since we perform two DFS traversals (one for the Pacific Ocean and one for the Atlantic Ocean), the overall time complexity is `O(2 * m * n)` or simply `O(m * n)`.

#### Space Complexity:
- We use two 2D matrices (`pac` and `atl`) to track whether each cell can reach the respective ocean. Each matrix takes `O(m * n)` space.
- The recursion stack for DFS can also take up to `O(m * n)` space in the worst case.
- Thus, the overall space complexity is `O(m * n)`.

### Conclusion

The solution effectively solves the problem of finding cells where water can flow to both the Pacific and Atlantic oceans by using depth-first search (DFS). The approach involves marking cells that can reach each ocean, and then collecting the coordinates where both oceans can be reached. The time and space complexity of the solution are both optimal for this problem, making it efficient even for larger matrices.

[`Link to LeetCode Lab`](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)

---
{{< youtube 1HDq998kmio >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
