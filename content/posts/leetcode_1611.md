
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1611: Minimum One Bit Operations to Make Integers Zero"
date = "2020-06-02"
description = "Solution to Leetcode 1611"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1)
            return n;
        int bit = 0;
        while ((1 << bit) <= n)
            bit++;
        return ((1 << bit) - 1) - minimumOneBitOperations(n - (1 << (bit-1)));         
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
