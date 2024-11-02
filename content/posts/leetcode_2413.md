
+++
authors = ["Crafted by Me"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2017-03-25"
description = "Solution to Leetcode 2413"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-even-multiple/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

