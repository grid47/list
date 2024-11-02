
+++
authors = ["Crafted by Me"]
title = "Leetcode 2327: Number of People Aware of a Secret"
date = "2017-06-19"
description = "Solution to Leetcode 2327"
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

