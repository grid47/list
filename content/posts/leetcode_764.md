
+++
authors = ["grid47"]
title = "Leetcode 764: Largest Plus Sign"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 764: Largest Plus Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-plus-sign/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n));
        for(auto &m: mines)
        grid[m[0]][m[1]] = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
            grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0? 0: l + 1));
            grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0? 0: r + 1));
            grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0? 0: u + 1));
            grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0? 0: d + 1));
        }

        int res = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res = max(grid[i][j], res);

        return res;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/764.md" >}}
---
{{< youtube dOSQVrCtO9w >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #765: Couples Holding Hands](https://grid47.xyz/posts/leetcode_765) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
