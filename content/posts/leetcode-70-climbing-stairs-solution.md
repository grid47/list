
+++
authors = ["grid47"]
title = "Leetcode 70: Climbing Stairs"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 70: Climbing Stairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/climbing-stairs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/70.webp" 
    alt="A glowing staircase with each step symbolizing progress, slowly leading upwards."
    caption="Solution to LeetCode 70: Climbing Stairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #71: Simplify Path](https://grid47.xyz/posts/leetcode-71-simplify-path-solution/) |
| --- |
