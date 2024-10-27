
+++
authors = ["Yasir"]
title = "Leetcode 2544: Alternating Digit Sum"
date = "2017-11-10"
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

{{< highlight html >}}
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

