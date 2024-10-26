
+++
authors = ["Yasir"]
title = "Leetcode 983: Minimum Cost For Tickets"
date = "2022-02-17"
description = "Solution to Leetcode 983"
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

{{< highlight html >}}
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

