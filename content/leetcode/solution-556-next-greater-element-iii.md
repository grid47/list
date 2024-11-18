
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
youtube = "-Ehc8QF1eac"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp"
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-element-iii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp" 
    alt="A sequence of numbers where each next greater element softly illuminates as it’s found for the next number."
    caption="Solution to LeetCode 556: Next Greater Element III Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #557: Reverse Words in a String III](https://grid47.xyz/leetcode/solution-557-reverse-words-in-a-string-iii/) |
| --- |
