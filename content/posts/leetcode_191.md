
+++
authors = ["Crafted by Me"]
title = "Leetcode 191: Number of 1 Bits"
date = "2023-04-25"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/191.md" >}}
---
{{< youtube 1JfdvPk-iHg >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

