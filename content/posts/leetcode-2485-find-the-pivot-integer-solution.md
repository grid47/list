
+++
authors = ["grid47"]
title = "Leetcode 2485: Find the Pivot Integer"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2485: Find the Pivot Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-pivot-integer/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2485.md" >}}
---
{{< youtube Xfw3A8uOdFw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2486: Append Characters to String to Make Subsequence](https://grid47.xyz/posts/leetcode-2486-append-characters-to-string-to-make-subsequence-solution/) |
| --- |
