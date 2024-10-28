
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2304: Minimum Path Cost in a Grid"
date = "2018-07-09"
description = "Solution to Leetcode 2304"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    
    vector<vector<int>> grid, cost, memo;
    
    int dp(int x, int y) {
        
        if(x == m - 1) return grid[x][y];
        
        if(memo[x][y] != -1) return memo[x][y];
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        ans = min(ans, dp(x + 1, i) + grid[x][y] + cost[grid[x][y]][i]);
        
        return memo[x][y] = ans;
        
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        this->grid = grid;
        this->cost = moveCost;
        m = grid.size();
        n = grid[0].size();
        
        memo.resize(m, vector<int>(n, -1));
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp(0, i));
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

