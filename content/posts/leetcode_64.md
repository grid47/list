
+++
authors = ["Yasir"]
title = "Leetcode 64: Minimum Path Sum"
date = "2024-08-22"
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

**Code:**

{{< highlight html >}}
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

