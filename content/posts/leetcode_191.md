
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 191: Number of 1 Bits"
date = "2024-04-21"
description = "Solution to Leetcode 191"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-1-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int key = 0;
        while(n) {
            n = n & (n - 1);
            key++;
        }
        return key;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

