
+++
authors = ["Yasir"]
title = "Leetcode 63: Unique Paths II"
date = "2024-08-23"
description = "Solution to Leetcode 63"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-paths-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0] == 1? 0: 1;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            
            if(grid[i][j] != 1) {
                dp[i][j] += ((i > 0 && grid[i - 1][j] == 0)? dp[i - 1][j]: 0) +
                        ((j > 0 && grid[i][j - 1] == 0)? dp[i][j - 1]: 0);
            }
            
        }
        return dp[m - 1][n - 1];
    }
};
{{< /highlight >}}

