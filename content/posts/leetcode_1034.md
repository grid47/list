
+++
authors = ["grid47"]
title = "Leetcode 1034: Coloring A Border"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1034: Coloring A Border in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1035: Uncrossed Lines](https://grid47.xyz/posts/leetcode_1035) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
