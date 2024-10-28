
+++
authors = ["Yasir"]
title = "Leetcode 1672: Richest Customer Wealth"
date = "2020-04-01"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

