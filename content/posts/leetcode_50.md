
+++
authors = ["Yasir"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-09-09"
description = "Solution to Leetcode 50"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powx-n/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    double myPow(double x, int n) {
        if(n== 0) return 1;
        if(n < 0) return 1/x * myPow(1/x, -(n + 1));
        
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

