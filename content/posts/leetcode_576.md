
+++
authors = ["Crafted by Me"]
title = "Leetcode 576: Out of Boundary Paths"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 576: Out of Boundary Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/out-of-boundary-paths/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = (int) 1e9 + 7;
public:
    int findPaths(int m, int n, int mv, int i, int j) {
        
        vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        
        return dfs(m, n, mv, 0, i, j, mm);
        
    }
    
    int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {

        if (x < 0 || y < 0 || x >= m || y >= n) return 1;
        if (mv == mx)                           return 0;
        if (mm[mv][x][y] > -1)                  return mm[mv][x][y];

        int res = 0;
        res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;

        return mm[mv][x][y] = (res % mod);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/576.md" >}}
---
{{< youtube Bg5CLRqtNmk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #577: Employee Bonus](https://grid47.xyz/posts/leetcode_577) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
