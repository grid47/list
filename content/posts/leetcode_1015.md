
+++
authors = ["Crafted by Me"]
title = "Leetcode 1015: Smallest Integer Divisible by K"
date = "2021-01-21"
description = "Solution to Leetcode 1015"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-integer-divisible-by-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int r = 0, N = 1; N <= k; N++)
        if((r = (r * 10 + 1)%k )== 0) return N;
        return -1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

