
+++
authors = ["grid47"]
title = "Leetcode 556: Next Greater Element III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 556: Next Greater Element III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","String"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #557: Reverse Words in a String III](https://grid47.xyz/posts/leetcode-557-reverse-words-in-a-string-iii-solution/) |
| --- |
