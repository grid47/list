
+++
authors = ["Yasir"]
title = "Leetcode 188: Best Time to Buy and Sell Stock IV"
date = "2024-04-22"
description = "Solution to Leetcode 188"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int memo[2][1001][100];
    int dp(int k, vector<int>& prices, int buy, int idx, int cnt) {
        if(cnt == k || idx == prices.size()) {
            return 0;
        }
        if(memo[buy][idx][cnt] != -1) return memo[buy][idx][cnt];
        int res = dp(k, prices, buy, idx + 1, cnt);
        if(buy) {
            res = max(res, -prices[idx] + dp(k, prices, false, idx + 1, cnt));
        } else {
            res = max(res, prices[idx] + dp(k, prices, true, idx +1, cnt + 1));            
        }
        return memo[buy][idx][cnt] = res;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return dp(k,prices, true, 0, 0);
    }
};
{{< /highlight >}}

