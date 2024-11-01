
+++
authors = ["Crafted by Me"]
title = "Leetcode 764: Largest Plus Sign"
date = "2022-09-30"
description = "Solution to Leetcode 764"
tags = [
    
]
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
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

