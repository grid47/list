
+++
authors = ["grid47"]
title = "Leetcode 1034: Coloring A Border"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1034: Coloring A Border in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/coloring-a-border/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, int cl) {
 
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || c < 0 || r >=  m || c >= n || grid[r][c] != cl) return;

        grid[r][c] = -cl;
        
        dfs(grid, r + 1, c, cl);
        dfs(grid, r - 1, c, cl);
        dfs(grid, r, c + 1, cl);
        dfs(grid, r, c - 1, cl);
        
        if(  r > 0 && c > 0 && r < m -1 && c < n - 1 &&
            abs(grid[r+1][c]) == cl && abs(grid[r-1][c]) == cl && 
            abs(grid[r][c+1]) == cl && abs(grid[r][c-1]) == cl )
        {
             grid[r][c] = cl;
        }  
        
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dfs(grid, row, col, grid[row][col]);
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = grid[i][j] < 0? color:grid[i][j];
        return grid;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1034.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1035: Uncrossed Lines](https://grid47.xyz/leetcode/solution-1035-uncrossed-lines/) |
| --- |