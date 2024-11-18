
+++
authors = ["grid47"]
title = "Leetcode 1910: Remove All Occurrences of a Substring"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1910: Remove All Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int m = part.size(), n = s.size(), i, j;
        for(i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1910.md" >}}
---
{{< youtube d74CJIqw268 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1911: Maximum Alternating Subsequence Sum](https://grid47.xyz/leetcode/solution-1911-maximum-alternating-subsequence-sum/) |
| --- |
