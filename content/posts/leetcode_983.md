
+++
authors = ["Crafted by Me"]
title = "Leetcode 983: Minimum Cost For Tickets"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 983: Minimum Cost For Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {

        int d = days.back();
        vector<int>  dp(d + 1, 0);
        vector<bool> td(d + 1, false);

        for(int x : days) td[x] = true;

        for(int i = 1; i < d + 1; i++) {
            if(!td[i]) {
                dp[i] = dp[i - 1];
                continue;
            }
            
            dp[i] = dp[i - 1] + cost[0];
            dp[i] = min(dp[i], cost[1] + dp[max(i - 7, 0)]);
            dp[i] = min(dp[i], cost[2] + dp[max(i - 30, 0)]);            

        }

        return dp[d];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/983.md" >}}
---
{{< youtube akXV67u1pTg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #984: String Without AAA or BBB](https://grid47.xyz/posts/leetcode_984) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

