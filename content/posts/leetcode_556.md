
+++
authors = ["Crafted by Me"]
title = "Leetcode 556: Next Greater Element III"
date = "2023-04-26"
description = "In-depth solution and explanation for Leetcode 556: Next Greater Element III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/556.md" >}}
---
{{< youtube -Ehc8QF1eac >}}
| Next : [LeetCode #557: Reverse Words in a String III](https://grid47.xyz/posts/leetcode_557) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

