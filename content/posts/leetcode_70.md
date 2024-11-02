
+++
authors = ["Crafted by Me"]
title = "Leetcode 70: Climbing Stairs"
date = "2023-08-24"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/70.md" >}}
---
{{< youtube I-R1XsECJu8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

