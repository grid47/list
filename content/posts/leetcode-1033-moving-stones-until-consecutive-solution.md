
+++
authors = ["grid47"]
title = "Leetcode 1033: Moving Stones Until Consecutive"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1033: Moving Stones Until Consecutive in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/moving-stones-until-consecutive/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s {a, b, c};
        sort(s.begin(), s.end());
        
        if(s[2]-s[0] == 2) return {0, 0};
        
        
        
        return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1033.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1034: Coloring A Border](https://grid47.xyz/posts/leetcode-1034-coloring-a-border-solution/) |
| --- |
