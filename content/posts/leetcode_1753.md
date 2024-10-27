
+++
authors = ["Yasir"]
title = "Leetcode 1753: Maximum Score From Removing Stones"
date = "2020-01-10"
description = "Solution to Leetcode 1753"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // a > b > c
        if(a < b)
        return maximumScore(b, a, c);
        if(b < c)
        return maximumScore(a, c, b);

        return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
    }
};
{{< /highlight >}}

