
+++
authors = ["Yasir"]
title = "Leetcode 70: Climbing Stairs"
date = "2024-08-16"
description = "Solution to Leetcode 70"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/climbing-stairs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n  + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n];
    }
};
{{< /highlight >}}

