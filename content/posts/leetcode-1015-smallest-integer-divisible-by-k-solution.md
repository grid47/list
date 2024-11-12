
+++
authors = ["grid47"]
title = "Leetcode 1015: Smallest Integer Divisible by K"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1015: Smallest Integer Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-integer-divisible-by-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for(int r = 0, N = 1; N <= k; N++)
        if((r = (r * 10 + 1)%k )== 0) return N;
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1015.md" >}}
---
{{< youtube kaEYJUNhQ3k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1016: Binary String With Substrings Representing 1 To N](https://grid47.xyz/posts/leetcode-1016-binary-string-with-substrings-representing-1-to-n-solution/) |
| --- |
