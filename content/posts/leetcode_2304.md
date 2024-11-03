
+++
authors = ["Crafted by Me"]
title = "Leetcode 2304: Minimum Path Cost in a Grid"
date = "2018-07-13"
description = "In-depth solution and explanation for Leetcode 2304: Minimum Path Cost in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 2305: Fair Distribution of Cookies |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

