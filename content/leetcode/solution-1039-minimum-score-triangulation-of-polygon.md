
+++
authors = ["grid47"]
title = "Leetcode 1039: Minimum Score Triangulation of Polygon"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1039: Minimum Score Triangulation of Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1039.md" >}}
---
{{< youtube plKzOVMehqo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1040: Moving Stones Until Consecutive II](https://grid47.xyz/leetcode/solution-1040-moving-stones-until-consecutive-ii/) |
| --- |
