
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 190: Reverse Bits"
date = "2024-04-24"
description = "Solution to Leetcode 190"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0xffffffff) << 16 | (n & 0xffffffff) >> 16;
        n = (n & 0x00ff00ff) << 8  | (n & 0xff00ff00) >> 8;
        n = (n & 0x0f0f0f0f) << 4  | (n & 0xf0f0f0f0) >> 4;
        n = (n & 0x33333333) << 2  | (n & 0xcccccccc) >> 2;
        n = (n & 0x55555555) << 1  | (n & 0xaaaaaaaa) >> 1;        
        return n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/190.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

