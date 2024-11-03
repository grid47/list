
+++
authors = ["Crafted by Me"]
title = "Leetcode 746: Min Cost Climbing Stairs"
date = "2022-10-18"
description = "In-depth solution and explanation for Leetcode 746: Min Cost Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube fPnQWeFlBCU >}}
| Next : [LeetCode #747: Largest Number At Least Twice of Others](https://grid47.xyz/posts/leetcode_747) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

