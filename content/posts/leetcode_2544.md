
+++
authors = ["Crafted by Me"]
title = "Leetcode 2544: Alternating Digit Sum"
date = "2016-11-14"
description = "Solution to Leetcode 2544"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/alternating-digit-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int sgn = 1;
        while(n) {
            sum += sgn * (n % 10);
            n /= 10;
            sgn *= -1;
        }
        return sgn == -1? sum : -sum;
    }
};
{{< /highlight >}}


---
{{< youtube IFRYDmhEWGw >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

