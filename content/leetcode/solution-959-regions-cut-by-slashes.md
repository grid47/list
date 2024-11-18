
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
+++



[`Problem Link`](https://leetcode.com/problems/regions-cut-by-slashes/description/)

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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/959.md" >}}
---
{{< youtube j8KrBYIxHK8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #962: Maximum Width Ramp](https://grid47.xyz/leetcode/solution-962-maximum-width-ramp/) |
| --- |
