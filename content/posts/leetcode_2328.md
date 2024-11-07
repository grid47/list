
+++
authors = ["Crafted by Me"]
title = "Leetcode 2328: Number of Increasing Paths in a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2328: Number of Increasing Paths in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Depth-First Search","Breadth-First Search","Graph","Topological Sort","Memoization","Matrix"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<vector<int>> dp;

    int mem(int i, int j, vector<vector<int>> & grid) {
        long res = 1;
        if(dp[i][j] != -1) return dp[i][j];
        int dir[] = {0, 1, 0, -1, 0};
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k], y = j + dir[k + 1];
            if(x < 0 || y < 0 || x >= dp.size() || y >= dp[0].size() || grid[x][y] <= grid[i][j])
                continue;
            res = (res + mem(x, y, grid)) % mod;
        }
        return dp[i][j] = res % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        long res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            res = (res + mem(i, j, grid)) % mod;
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2328.md" >}}
---
{{< youtube jqPLjcYEV64 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2331: Evaluate Boolean Binary Tree](https://grid47.xyz/posts/leetcode_2331) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
