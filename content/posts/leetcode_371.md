
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 371: Sum of Two Integers"
date = "2023-10-24"
description = "Solution to Leetcode 371"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-two-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0? a: getSum(a^b, (a&b)<<1);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

