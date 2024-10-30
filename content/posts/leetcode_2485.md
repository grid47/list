
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2485: Find the Pivot Integer"
date = "2018-01-11"
description = "Solution to Leetcode 2485"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-pivot-integer/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2, x = sqrt(sum);
        return x * x == sum ? x : -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

