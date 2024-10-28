
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1359: Count All Valid Pickup and Delivery Options"
date = "2021-02-08"
description = "Solution to Leetcode 1359"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOrders(int n) {
        long res = 1;
        int mod = (int) 1e9 + 7;
        for(int i = 1; i <= n; i++)
        res = (res * (2 * i - 1) * i) % mod;
        
        return (int) res;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

