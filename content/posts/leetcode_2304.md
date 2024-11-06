
+++
authors = ["Crafted by Me"]
title = "Leetcode 2304: Minimum Path Cost in a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2304: Minimum Path Cost in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
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
{{< youtube v_a0S1Tjuxk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2305: Fair Distribution of Cookies](https://grid47.xyz/posts/leetcode_2305) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
