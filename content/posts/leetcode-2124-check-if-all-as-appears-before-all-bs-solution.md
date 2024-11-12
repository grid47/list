
+++
authors = ["grid47"]
title = "Leetcode 2124: Check if All A's Appears Before All B's"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2124: Check if All A's Appears Before All B's in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool checkString(string s) {
        return s.find("ba")==string::npos;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2124.md" >}}
---
{{< youtube RgzM3HRkdp8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2125: Number of Laser Beams in a Bank](https://grid47.xyz/posts/leetcode-2125-number-of-laser-beams-in-a-bank-solution/) |
| --- |
