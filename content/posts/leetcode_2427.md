
+++
authors = ["Crafted by Me"]
title = "Leetcode 2427: Number of Common Factors"
date = "2017-03-11"
description = "Solution to Leetcode 2427"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-common-factors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int commonFactors(int a, int b) {
    int res = 1, hi = gcd(a, b);
    for (int n = 2; n <= hi; ++n)
        res += a % n == 0 && b % n == 0;
    return res;
}
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

