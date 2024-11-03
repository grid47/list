
+++
authors = ["Crafted by Me"]
title = "Leetcode 1463: Cherry Pickup II"
date = "2020-10-31"
description = "In-depth solution and explanation for Leetcode 1463: Cherry Pickup II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1463.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1464: Maximum Product of Two Elements in an Array](https://grid47.xyz/posts/leetcode_1464) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

