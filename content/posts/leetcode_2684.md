
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2684: Maximum Number of Moves in a Grid"
date = "2017-06-26"
description = "Solution to Leetcode 2684"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid, mem;
    
    int dfs(int p, int q) {
        
        if(mem[p][q] != -1) return mem[p][q];
        int ans = 0;
        if(p - 1>= 0 && q + 1 < n && grid[p - 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p - 1, q + 1));
        if(p     < m && q + 1 < n && grid[p][q + 1]     > grid[p][q]) ans = max(ans, 1 + dfs(p    , q + 1));
        if(p + 1 < m && q + 1 < n && grid[p + 1][q + 1] > grid[p][q]) ans = max(ans, 1 + dfs(p + 1, q + 1));

        return mem[p][q] = ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        mem.resize(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            ans = max(ans, dfs(i, 0));
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

