
+++
authors = ["Crafted by Me"]
title = "Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        int days = prices.size();
        vector<int> buy(days, 0), sell(days, 0);
        buy[0]= -prices[0]-fee;
        for(int i = 1; i < days; i++) {
            buy[i] = max(buy[i -1], sell[i -1]-prices[i]-fee);
            sell[i] = max(sell[i -1], buy[i - 1]+prices[i]);
        }
        return sell[days - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/714.md" >}}
---
{{< youtube HLr_OnShK4s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #715: Range Module](https://grid47.xyz/posts/leetcode_715) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

