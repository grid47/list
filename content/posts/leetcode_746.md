
+++
authors = ["Yasir"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2022-10-12"
description = "Solution to Leetcode 746"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n + 1, 0);
        
        for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        
        return dp[n];
    }
};
{{< /highlight >}}

