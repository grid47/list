
+++
authors = ["grid47"]
title = "Leetcode 1753: Maximum Score From Removing Stones"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1753: Maximum Score From Removing Stones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // a > b > c
        if(a < b)
        return maximumScore(b, a, c);
        if(b < c)
        return maximumScore(a, c, b);

        return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1753.md" >}}
---
{{< youtube PfcEkLJ725o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1754: Largest Merge Of Two Strings](https://grid47.xyz/leetcode/solution-1754-largest-merge-of-two-strings/) |
| --- |
