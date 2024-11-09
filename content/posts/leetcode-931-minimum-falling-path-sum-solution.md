
+++
authors = ["grid47"]
title = "Leetcode 931: Minimum Falling Path Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 931: Minimum Falling Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-falling-path-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mtx) {
        
        int m = mtx.size(), n = mtx[0].size();

        for(int i = 1; i < m; i++)
        for(int j = 0; j < n; j++) {

            int l = max(j - 1, 0);
            int r = min(j + 1, n - 1);

            mtx[i][j] += min(mtx[i- 1][l], min(mtx[i - 1][j], mtx[i - 1][r]));

        }

        int res = mtx[m - 1][0];
        for(int j = 0; j < n; j++)
        res = min(res, mtx[m - 1][j]);

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/931.md" >}}
---
{{< youtube b_F3mz9l-uQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #934: Shortest Bridge](https://grid47.xyz/posts/leetcode-934-shortest-bridge-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
