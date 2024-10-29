
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 121: Best Time to Buy and Sell Stock"
date = "2024-07-01"
description = "Solution to Leetcode 121"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices[0], g = 0;
        for(int x: prices) {
            l = min(l, x);
            g = max(g, x - l);
        }
        return g;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/121.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

