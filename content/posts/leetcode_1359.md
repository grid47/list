
+++
authors = ["Crafted by Me"]
title = "Leetcode 1359: Count All Valid Pickup and Delivery Options"
date = "2020-02-12"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

