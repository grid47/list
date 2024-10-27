
+++
authors = ["Yasir"]
title = "Leetcode 121: Best Time to Buy and Sell Stock"
date = "2024-06-29"
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

{{< highlight html >}}
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

