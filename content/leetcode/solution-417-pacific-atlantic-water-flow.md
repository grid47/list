
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



[`Problem Link`](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/417.md" >}}
---
{{< youtube 1HDq998kmio >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #419: Battleships in a Board](https://grid47.xyz/leetcode/solution-419-battleships-in-a-board/) |
| --- |
