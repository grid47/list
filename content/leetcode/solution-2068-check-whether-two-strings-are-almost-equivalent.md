
+++
authors = ["grid47"]
title = "Leetcode 2068: Check Whether Two Strings are Almost Equivalent"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2068: Check Whether Two Strings are Almost Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2068.md" >}}
---
{{< youtube l_KAgx9c8Mc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2069: Walking Robot Simulation II](https://grid47.xyz/leetcode/solution-2069-walking-robot-simulation-ii/) |
| --- |
