
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 417: Pacific Atlantic Water Flow"
date = "2023-09-08"
description = "Solution to Leetcode 417"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

