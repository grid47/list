
+++
authors = ["Yasir"]
title = "Leetcode 695: Max Area of Island"
date = "2022-12-03"
description = "Solution to Leetcode 695"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-area-of-island/description/)

---

**Code:**

{{< highlight html >}}
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

