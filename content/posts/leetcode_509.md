
+++
authors = ["Yasir"]
title = "Leetcode 509: Fibonacci Number"
date = "2023-06-06"
description = "Solution to Leetcode 509"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fibonacci-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
            
        return dp[n];
    }
};
{{< /highlight >}}

