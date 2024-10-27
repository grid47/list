
+++
authors = ["Yasir"]
title = "Leetcode 200: Number of Islands"
date = "2024-04-11"
description = "Solution to Leetcode 200"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-islands/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '1') {
                cnt++;
                dfs(grid, i, j);
            }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}

