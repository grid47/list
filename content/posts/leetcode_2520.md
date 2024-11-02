
+++
authors = ["Crafted by Me"]
title = "Leetcode 2520: Count the Digits That Divide a Number"
date = "2016-12-08"
description = "Solution to Leetcode 2520"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int n = num; n > 0; n /= 10)
            res += num % (n % 10) == 0;
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube 7SHHsS5kPJ8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

