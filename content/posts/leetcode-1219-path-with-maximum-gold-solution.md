
+++
authors = ["grid47"]
title = "Leetcode 1219: Path with Maximum Gold"
date = "2024-07-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1219: Path with Maximum Gold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-with-maximum-gold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxGold = max(maxGold, findMax(grid, m, n, i, j));
        return maxGold;
    }
    
    int dir[5] = {0,1,0,-1,0};
    
    int findMax(vector<vector<int>> &grid, int m,int n, int r, int c) {
        if(r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0)
            return 0;
        int origin = grid[r][c];
        grid[r][c] = 0;
        int mx = 0;
        for(int i = 0; i < 4; i++)
            mx = max(mx, findMax(grid, m, n, r+dir[i], c+dir[i+1]));
        grid[r][c]=origin;
        return mx+origin;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1219.md" >}}
---
{{< youtube I1wllM_pozY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1222: Queens That Can Attack the King](https://grid47.xyz/posts/leetcode-1222-queens-that-can-attack-the-king-solution/) |
| --- |
