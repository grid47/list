
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1034: Coloring A Border"
date = "2022-01-01"
description = "Solution to Leetcode 1034"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coloring-a-border/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

