
+++
authors = ["Yasir"]
title = "Leetcode 1952: Three Divisors"
date = "2019-06-26"
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

