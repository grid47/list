
+++
authors = ["Yasir"]
title = "Leetcode 931: Minimum Falling Path Sum"
date = "2022-04-10"
description = "Solution to Leetcode 931"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-falling-path-sum/description/)

---

**Code:**

{{< highlight html >}}
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

