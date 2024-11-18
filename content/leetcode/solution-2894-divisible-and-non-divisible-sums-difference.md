
+++
authors = ["grid47"]
title = "Leetcode 2894: Divisible and Non-divisible Sums Difference"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2894: Divisible and Non-divisible Sums Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "CXjNaWOdJ34"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                res -= i;
            } else {
                res += i;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2894.md" >}}
---
{{< youtube CXjNaWOdJ34 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2895: Minimum Processing Time](https://grid47.xyz/leetcode/solution-2895-minimum-processing-time/) |
| --- |
