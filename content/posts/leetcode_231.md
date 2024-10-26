
+++
authors = ["Yasir"]
title = "Leetcode 231: Power of Two"
date = "2024-03-10"
description = "Solution to Leetcode 231"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/power-of-two/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n - 1));
    }
};
{{< /highlight >}}

