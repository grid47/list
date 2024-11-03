
+++
authors = ["Crafted by Me"]
title = "Leetcode 64: Minimum Path Sum"
date = "2024-08-30"
description = "In-depth solution and explanation for Leetcode 64: Minimum Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-path-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
                 if(i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            else if(i > 0) grid[i][j] += grid[i - 1][j];
            else if(j > 0) grid[i][j] += grid[i][j - 1];
        }
        
        return grid[m - 1][n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/64.md" >}}
---
{{< youtube pGMsrvt0fpk >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

