
+++
authors = ["Yasir"]
title = "Leetcode 861: Score After Flipping Matrix"
date = "2022-06-19"
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

{{< highlight html >}}
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

