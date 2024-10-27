
+++
authors = ["Yasir"]
title = "Leetcode 1015: Smallest Integer Divisible by K"
date = "2022-01-17"
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

{{< highlight html >}}
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int r = 0, N = 1; N <= k; N++)
        if((r = (r * 10 + 1)%k )== 0) return N;
        return -1;
    }
};
{{< /highlight >}}

