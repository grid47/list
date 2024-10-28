
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2220: Minimum Bit Flips to Convert Number"
date = "2018-10-01"
description = "Solution to Leetcode 2220"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

