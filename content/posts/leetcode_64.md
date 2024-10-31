
+++
authors = ["Crafted by Me"]
title = "Leetcode 64: Minimum Path Sum"
date = "2024-08-29"
description = "Solution to Leetcode 64"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-path-sum/description/)

---

{{< youtube pGMsrvt0fpk >}}

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

