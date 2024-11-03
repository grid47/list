
+++
authors = ["Crafted by Me"]
title = "Leetcode 1559: Detect Cycles in 2D Grid"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1559: Detect Cycles in 2D Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-cycles-in-2d-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++) 
        if(!vis[i][j] && dfs(grid, vis, i, j, -1, -1, grid[i][j])) return true;
        
        return false;
        
    }
    
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int pi, int pj, char node) {
        
        if(vis[i][j]) return true;
        
        vis[i][j] = true;

        for(auto d: dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(min(ni, nj) < 0 || 
               ni > grid.size() - 1 || 
               nj > grid[0].size() - 1 ||
               grid[ni][nj] != node)
                continue;
            if((ni == pi) && (nj == pj)) continue;
            
            if(dfs(grid, vis, ni, nj, i, j, node))
                return true;
            
        }
        
        return false;
        
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1559.md" >}}
---
{{< youtube eQvsVEt_j8M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1560: Most Visited Sector in  a Circular Track](https://grid47.xyz/posts/leetcode_1560) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

