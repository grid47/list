
+++
authors = ["grid47"]
title = "Leetcode 1974: Minimum Time to Type Word Using Special Typewriter"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1974: Minimum Time to Type Word Using Special Typewriter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size(), point = 'a';
        for (auto ch : word) {
            res += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1974.md" >}}
---
{{< youtube DEMUS-1tq-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1975: Maximum Matrix Sum](https://grid47.xyz/leetcode/solution-1975-maximum-matrix-sum/) |
| --- |
