
+++
authors = ["Crafted by Me"]
title = "Leetcode 63: Unique Paths II"
date = "2024-08-31"
description = "In-depth solution and explanation for Leetcode 63: Unique Paths II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/63.md" >}}
---
{{< youtube d3UOz7zdE4I >}}

"| 64: Minimum Path Sum |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

