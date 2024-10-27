
+++
authors = ["Yasir"]
title = "Leetcode 371: Sum of Two Integers"
date = "2023-10-23"
description = "Solution to Leetcode 371"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-two-integers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0? a: getSum(a^b, (a&b)<<1);
    }
};
{{< /highlight >}}

