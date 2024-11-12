
+++
authors = ["grid47"]
title = "Leetcode 2327: Number of People Aware of a Secret"
date = "2024-03-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2327: Number of People Aware of a Secret in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Queue","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        int res = 0, share = 0;
        vector<long> dp(n + 2, 0);
        dp[1] = 1;
        int mod = 1e9 + 7;
        for(int i = 2; i <= n; i++)
            dp[i] = share = (share + dp[max(i - delay, 0)] - dp[max(i - forget, 0)] + mod) % mod;
        
        for(int i = n + 1 - forget; i <= n; i++)
            res = (res + dp[i]) % mod;
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2327.md" >}}
---
{{< youtube rOnTeyl_njo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2331: Evaluate Boolean Binary Tree](https://grid47.xyz/posts/leetcode-2331-evaluate-boolean-binary-tree-solution/) |
| --- |
