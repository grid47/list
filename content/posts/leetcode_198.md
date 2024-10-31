
+++
authors = ["Crafted by Me"]
title = "Leetcode 198: House Robber"
date = "2024-04-17"
description = "Solution to Leetcode 198"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/house-robber/description/)

---

{{< youtube UVNgW5nSoiU >}}

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

