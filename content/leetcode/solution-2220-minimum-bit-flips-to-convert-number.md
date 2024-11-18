
+++
authors = ["grid47"]
title = "Leetcode 2220: Minimum Bit Flips to Convert Number"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2220: Minimum Bit Flips to Convert Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "yz48myznqQY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2220.md" >}}
---
{{< youtube yz48myznqQY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2221: Find Triangular Sum of an Array](https://grid47.xyz/leetcode/solution-2221-find-triangular-sum-of-an-array/) |
| --- |
