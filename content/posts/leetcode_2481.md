
+++
authors = ["Yasir"]
title = "Leetcode 2481: Minimum Cuts to Divide a Circle"
date = "2018-01-12"
description = "Solution to Leetcode 2481"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        return n % 2 ? n : n / 2;
    }
};
{{< /highlight >}}

