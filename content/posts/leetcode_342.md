
+++
authors = ["Yasir"]
title = "Leetcode 342: Power of Four"
date = "2023-11-20"
description = "Solution to Leetcode 342"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/power-of-four/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};
{{< /highlight >}}

