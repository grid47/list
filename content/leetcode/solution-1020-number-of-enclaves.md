
+++
authors = ["grid47"]
title = "Leetcode 1020: Number of Enclaves"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1020: Number of Enclaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-enclaves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                if(grid[i][j] == 1)
                    dfs(grid, i, j);
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1) cnt++;
        
        return cnt;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1020.md" >}}
---
{{< youtube BcrKHwawGb8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1023: Camelcase Matching](https://grid47.xyz/leetcode/solution-1023-camelcase-matching/) |
| --- |
