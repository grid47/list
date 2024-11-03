
+++
authors = ["Crafted by Me"]
title = "Leetcode 198: House Robber"
date = "2024-04-18"
description = "In-depth solution and explanation for Leetcode 198: House Robber in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/house-robber/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> dp(n,0);
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for(int i = 2; i < n; i++)
            dp[i] = max(dp[i-2]+a[i], dp[i-1]);
        return dp[n-1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/198.md" >}}
---
{{< youtube UVNgW5nSoiU >}}

| Next : [LeetCode #199: Binary Tree Right Side View](grid47.xyz/leetcode_199) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

