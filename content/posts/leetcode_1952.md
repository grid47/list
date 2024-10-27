
+++
authors = ["Yasir"]
title = "Leetcode 1952: Three Divisors"
date = "2019-06-25"
description = "Solution to Leetcode 1952"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/three-divisors/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isThree(int n) {
    int d = 2;
    for (int i = 2; i < n && d <= 3; i += 1)
        d += n % i == 0;
    return d == 3;
}
};
{{< /highlight >}}

