
+++
authors = ["Crafted by Me"]
title = "Leetcode 2684: Maximum Number of Moves in a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2684: Maximum Number of Moves in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2684.md" >}}
---
{{< youtube MQQZiN9CnDk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2685: Count the Number of Complete Components](https://grid47.xyz/posts/leetcode_2685) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
