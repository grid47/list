
+++
authors = ["Yasir"]
title = "Leetcode 2658: Maximum Number of Fish in a Grid"
date = "2017-07-20"
description = "Solution to Leetcode 2658"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        this->grid = grid;
        int mx = 0;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != 0) {
                mx = max(mx, dfs(i, j));
            }
        return mx;
    }
    
    int dfs(int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        
        ans += dfs(i + 1, j);
        ans += dfs(i - 1, j);
        ans += dfs(i, j + 1);
        ans += dfs(i, j - 1);
        
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

