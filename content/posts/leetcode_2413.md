
+++
authors = ["Yasir"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2018-03-21"
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

{{< highlight html >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}

