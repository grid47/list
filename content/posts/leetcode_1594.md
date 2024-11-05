
+++
authors = ["Crafted by Me"]
title = "Leetcode 1594: Maximum Non Negative Product in a Matrix"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1594: Maximum Non Negative Product in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<long long>> memo;
    int mod = (int) 1e9 + 7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        this->m = grid.size();
        this->n = grid[0].size();
        this->grid = grid;
        
        memo.resize(m, vector<long long>(n, LLONG_MIN));
        
        int ans = dfs(0, 0, 1) % mod;
        
        return ans < 0? -1: ans;
        
    }
    
    long long dfs(int i, int j, long long val) {
        
        if(i == m - 1 && j == n - 1) return (val * grid[i][j]);

        // if(memo[i][j] != LLONG_MIN) return memo[i][j];
        long long ans = LLONG_MIN;
        
        if(grid[i][j] == 0) return 0;
        
        if(i + 1 < m)
        ans = max(ans, dfs(i + 1, j, val * grid[i][j]));

        if(j + 1 < n)            
        ans = max(ans, dfs(i, j + 1, val * grid[i][j]));
        
        // return memo[i][j] = ans;
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1594.md" >}}
---
{{< youtube zGDdmRr1YIQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1595: Minimum Cost to Connect Two Groups of Points](https://grid47.xyz/posts/leetcode_1595) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

