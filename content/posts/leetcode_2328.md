
+++
authors = ["Crafted by Me"]
title = "Leetcode 2328: Number of Increasing Paths in a Grid"
date = "2017-06-18"
description = "Solution to Leetcode 2328"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<vector<int>> dp;

    int mem(int i, int j, vector<vector<int>> & grid) {
        long res = 1;
        if(dp[i][j] != -1) return dp[i][j];
        int dir[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if(x < 0 || y < 0 || x >= dp.size() || y >= dp[0].size() || grid[x][y] <= grid[i][j])
                continue;
            res = (res + mem(x, y, grid)) % mod;
        }
        return dp[i][j] = res % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        long res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            res = (res + mem(i, j, grid)) % mod;
        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

