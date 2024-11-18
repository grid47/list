
+++
authors = ["grid47"]
title = "Leetcode 695: Max Area of Island"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 695: Max Area of Island in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/695.webp"
youtube = "rowp_Frq_eI"
youtube_upload_date="2024-05-07"
youtube_thumbnail="https://i.ytimg.com/vi/rowp_Frq_eI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/max-area-of-island/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/695.webp" 
    alt="A map of islands where the maximum area is calculated and softly glowing as the largest island is found."
    caption="Solution to LeetCode 695: Max Area of Island Problem"
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1)
                mx = max(mx, dfs(grid, i, j));
        return mx;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1)
            return 0;
        int ans = 1;
        grid[i][j] = 2;
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i, j + 1);
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i, j - 1);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/695.md" >}}
---
{{< youtube rowp_Frq_eI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #698: Partition to K Equal Sum Subsets](https://grid47.xyz/leetcode/solution-698-partition-to-k-equal-sum-subsets/) |
| --- |
