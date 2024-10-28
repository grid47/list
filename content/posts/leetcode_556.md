
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 556: Next Greater Element III"
date = "2023-04-22"
description = "Solution to Leetcode 556"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-element-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n)? -1: res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

