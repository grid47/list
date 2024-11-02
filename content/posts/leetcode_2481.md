
+++
authors = ["Crafted by Me"]
title = "Leetcode 2481: Minimum Cuts to Divide a Circle"
date = "2017-01-16"
description = "Solution to Leetcode 2481"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        return n % 2 ? n : n / 2;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

