
+++
authors = ["Crafted by Me"]
title = "Leetcode 2110: Number of Smooth Descent Periods of a Stock"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2110: Number of Smooth Descent Periods of a Stock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

---

**Code:**

{{< highlight cpp >}}
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


---
{{< youtube p_hKOwJ7azU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2111: Minimum Operations to Make the Array K-Increasing](https://grid47.xyz/posts/leetcode_2111) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
