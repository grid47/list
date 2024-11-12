
+++
authors = ["grid47"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 746: Min Cost Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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
---
{{< youtube fPnQWeFlBCU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #752: Open the Lock](https://grid47.xyz/posts/leetcode-752-open-the-lock-solution/) |
| --- |
