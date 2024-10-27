
+++
authors = ["Yasir"]
title = "Leetcode 1359: Count All Valid Pickup and Delivery Options"
date = "2021-02-07"
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

{{< highlight html >}}
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

