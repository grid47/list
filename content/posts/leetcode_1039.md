
+++
authors = ["Yasir"]
title = "Leetcode 1039: Minimum Score Triangulation of Polygon"
date = "2021-12-24"
description = "Solution to Leetcode 1039"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minScoreTriangulation(vector<int>& vals) {
        int dp[50][50] = {};
        
        int n = vals.size();
        
        for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            for(int k = i + 1; k < j; k++)
        dp[i][j] = min(dp[i][j] == 0? INT_MAX : dp[i][j], dp[i][k] + vals[i] * vals[k] * vals[j] + dp[k][j]);
        
        return dp[0][n - 1];
    }
};
{{< /highlight >}}

