
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 714: Best Time to Buy and Sell Stock with Transaction Fee"
date = "2022-11-16"
description = "Solution to Leetcode 714"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
