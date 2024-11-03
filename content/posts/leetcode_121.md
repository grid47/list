
+++
authors = ["Crafted by Me"]
title = "Leetcode 121: Best Time to Buy and Sell Stock"
date = "2024-07-04"
description = "In-depth solution and explanation for Leetcode 121: Best Time to Buy and Sell Stock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube kJZrMGpyWpk >}}

"| 122: Best Time to Buy and Sell Stock II |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

