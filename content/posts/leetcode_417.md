
+++
authors = ["Crafted by Me"]
title = "Leetcode 417: Pacific Atlantic Water Flow"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 417: Pacific Atlantic Water Flow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)

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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/417.md" >}}
---
{{< youtube 1HDq998kmio >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #418: Sentence Screen Fitting](https://grid47.xyz/posts/leetcode_418) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

