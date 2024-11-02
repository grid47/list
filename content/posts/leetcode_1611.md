
+++
authors = ["Crafted by Me"]
title = "Leetcode 1611: Minimum One Bit Operations to Make Integers Zero"
date = "2019-06-05"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

