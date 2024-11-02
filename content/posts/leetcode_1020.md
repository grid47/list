
+++
authors = ["Crafted by Me"]
title = "Leetcode 1020: Number of Enclaves"
date = "2021-01-16"
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


---
{{< youtube BcrKHwawGb8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

