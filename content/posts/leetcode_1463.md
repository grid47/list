
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1463: Cherry Pickup II"
date = "2020-10-28"
description = "Solution to Leetcode 1463"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cherry-pickup-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int dp[70][70][70] = {};
    int cherryPickup(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);
    }

    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {

        if (r == m) return 0; // Reach to bottom row
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc1 = c1 + i, nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {
                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));
                }
            }
        }

        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2] = ans + cherries;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
