
+++
authors = ["Yasir"]
title = "Leetcode 1551: Minimum Operations to Make Array Equal"
date = "2020-07-30"
description = "Solution to Leetcode 1551"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};
{{< /highlight >}}

