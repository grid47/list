
+++
authors = ["Crafted by Me"]
title = "Leetcode 2327: Number of People Aware of a Secret"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2327: Number of People Aware of a Secret in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube rOnTeyl_njo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2328: Number of Increasing Paths in a Grid](https://grid47.xyz/posts/leetcode_2328) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

