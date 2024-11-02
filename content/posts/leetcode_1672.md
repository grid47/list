
+++
authors = ["Crafted by Me"]
title = "Leetcode 1672: Richest Customer Wealth"
date = "2019-04-05"
description = "Solution to Leetcode 1672"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/richest-customer-wealth/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for (auto &customer : accounts)
            richest = max (richest, accumulate(customer.begin(), customer.end(), 0));
        
        return richest;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

