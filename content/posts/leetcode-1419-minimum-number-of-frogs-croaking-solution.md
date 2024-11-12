
+++
authors = ["grid47"]
title = "Leetcode 1419: Minimum Number of Frogs Croaking"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1419: Minimum Number of Frogs Croaking in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {}, frogs = 0, max_frog = 0;
        for(auto ch : croakOfFrogs) {
            auto n = string("croak").find(ch);
            ++cnt[n];
            if(n == 0) max_frog = max(max_frog, ++frogs);
            else if(--cnt[n - 1] < 0)   return -1;
            else if(n == 4)             --frogs;
        }
        return frogs == 0? max_frog : -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1419.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1422: Maximum Score After Splitting a String](https://grid47.xyz/posts/leetcode-1422-maximum-score-after-splitting-a-string-solution/) |
| --- |
