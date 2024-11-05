
+++
authors = ["Crafted by Me"]
title = "Leetcode 959: Regions Cut By Slashes"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 959: Regions Cut By Slashes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Depth-First Search","Union Find","Graph"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #960: Delete Columns to Make Sorted III](https://grid47.xyz/posts/leetcode_960) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

