
+++
authors = ["Yasir"]
title = "Leetcode 1020: Number of Enclaves"
date = "2022-01-12"
description = "Solution to Leetcode 1020"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-enclaves/description/)

---

**Code:**

{{< highlight html >}}
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

