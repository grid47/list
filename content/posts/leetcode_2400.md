
+++
authors = ["Crafted by Me"]
title = "Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps"
date = "2017-04-07"
description = "Solution to Leetcode 2400"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/)

---

**Code:**

{{< highlight cpp >}}
int dp[1001][1001] = {};
int mod = 1000000007;
class Solution {
public:
    int numberOfWays(int start, int end, int k) {
        return dfs(k, abs(start - end));
    }
    
    int dfs(int k, int d) {
        if (d >= k) return d == k;
        if(dp[k][d] == 0)
            dp[k][d] = (1 + dfs(k-1, d + 1) + dfs(k -1, abs(d -1))) % mod;
        
        return dp[k][d] -1;
        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

