
+++
authors = ["grid47"]
title = "Leetcode 63: Unique Paths II"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 63: Unique Paths II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-paths-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/63.webp" 
    alt="A more intricate, glowing path system with a few obstacles, showing varied routes to the goal."
    caption="Solution to LeetCode 63: Unique Paths II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #64: Minimum Path Sum](https://grid47.xyz/leetcode/solution-64-minimum-path-sum/) |
| --- |
