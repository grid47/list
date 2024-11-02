
+++
authors = ["Crafted by Me"]
title = "Leetcode 1254: Number of Closed Islands"
date = "2020-05-27"
description = "Solution to Leetcode 1254"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-closed-islands/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                if(grid[i][j] == 0)
                    dfs(grid, i, j, 0, 1);
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 0) {
                dfs(grid, i, j, 0, cnt + 2);
                    cnt++;
            }
        return cnt;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int cur, int tgt) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != cur)
            return;
        grid[i][j] = tgt;
        dfs(grid, i + 1, j, cur, tgt);
        dfs(grid, i, j + 1, cur, tgt);
        dfs(grid, i - 1, j, cur, tgt);
        dfs(grid, i, j - 1, cur, tgt);
    }
    
};
{{< /highlight >}}


---
{{< youtube ZH8TeWFYpx8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

