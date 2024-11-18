
+++
authors = ["grid47"]
title = "Leetcode 1768: Merge Strings Alternately"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1768: Merge Strings Alternately in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-strings-alternately/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int i = 0, j = 0;
        while(i < w1.size() || j < w2.size()) {
            if(i < w1.size()) {
                res += w1[i];
                i++;
            }
            if(j < w2.size()) {
                res += w2[j];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1768.md" >}}
---
{{< youtube oFuFTMu2Tgg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1769: Minimum Number of Operations to Move All Balls to Each Box](https://grid47.xyz/leetcode/solution-1769-minimum-number-of-operations-to-move-all-balls-to-each-box/) |
| --- |
