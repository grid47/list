
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2022-10-15"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/746.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

