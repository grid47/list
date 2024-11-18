
+++
authors = ["grid47"]
title = "Leetcode 2304: Minimum Path Cost in a Grid"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2304: Minimum Path Cost in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "v_a0S1Tjuxk"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2304.md" >}}
---
{{< youtube v_a0S1Tjuxk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2305: Fair Distribution of Cookies](https://grid47.xyz/leetcode/solution-2305-fair-distribution-of-cookies/) |
| --- |
