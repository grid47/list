
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 861: Score After Flipping Matrix"
date = "2022-06-23"
description = "Solution to Leetcode 861"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-after-flipping-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = (1 << n - 1) * m;

        for(int j = 1; j < n; j++) {
            int cur = 0;
            for(int i = 0; i < m; i++)
                cur += grid[i][0] == grid[i][j];
            res += max(cur, m - cur) * (1<<n-j-1);
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/861.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

