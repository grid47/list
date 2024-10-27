
+++
authors = ["Yasir"]
title = "Leetcode 1492: The kth Factor of n"
date = "2020-09-27"
description = "Solution to Leetcode 1492"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-kth-factor-of-n/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) k--;
            if(k == 0) return i;
        }
        return -1;
    }
};
{{< /highlight >}}

