
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2018-03-23"
description = "Solution to Leetcode 2413"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-even-multiple/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0? n: n * 2;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
