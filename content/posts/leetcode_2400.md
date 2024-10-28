
+++
authors = ["Yasir"]
title = "Leetcode 2400: Number of Ways to Reach a Position After Exactly k Steps"
date = "2018-04-04"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

