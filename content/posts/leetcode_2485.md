
+++
authors = ["Yasir"]
title = "Leetcode 2485: Find the Pivot Integer"
date = "2018-01-08"
description = "Solution to Leetcode 2485"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-pivot-integer/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2, x = sqrt(sum);
        return x * x == sum ? x : -1;
    }
};
{{< /highlight >}}

