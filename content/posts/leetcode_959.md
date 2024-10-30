
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 959: Regions Cut By Slashes"
date = "2022-03-17"
description = "Solution to Leetcode 959"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/regions-cut-by-slashes/description/)

---
{{< youtube nan >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/959.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

