
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1219: Path with Maximum Gold"
date = "2021-06-29"
description = "Solution to Leetcode 1219"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

