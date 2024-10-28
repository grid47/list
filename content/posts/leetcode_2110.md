
+++
authors = ["Yasir"]
title = "Leetcode 2110: Number of Smooth Descent Periods of a Stock"
date = "2019-01-19"
description = "Solution to Leetcode 2110"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        dp[0] = 1;
        long long ans = 1;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] == prices[i - 1] - 1)
            dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;
            ans += dp[i];
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

