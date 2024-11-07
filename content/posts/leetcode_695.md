
+++
authors = ["Crafted by Me"]
title = "Leetcode 695: Max Area of Island"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 695: Max Area of Island in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-area-of-island/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1)
                mx = max(mx, dfs(grid, i, j));
        return mx;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1)
            return 0;
        int ans = 1;
        grid[i][j] = 2;
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i, j + 1);
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i, j - 1);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/695.md" >}}
---
{{< youtube rowp_Frq_eI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #698: Partition to K Equal Sum Subsets](https://grid47.xyz/posts/leetcode_698) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
