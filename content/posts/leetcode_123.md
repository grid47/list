
+++
authors = ["Crafted by Me"]
title = "Leetcode 123: Best Time to Buy and Sell Stock III"
date = "2024-07-02"
description = "Solution to Leetcode 123"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int s1 = -prices[0], s2 = INT_MIN,
            s3 = INT_MIN, s4 = INT_MIN;
        
        int n = prices.size();
        
        for(int i = 1; i < n; i++) {
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1 + prices[i]);
            s3 = max(s3, s2 - prices[i]);
            s4 = max(s4, s3 + prices[i]);
        }
        
        return max(s4, 0);
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/123.md" >}}
- by gpt
        
---
{{< youtube 37s1_xBiqH0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

