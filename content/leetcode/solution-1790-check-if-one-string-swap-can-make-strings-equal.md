
+++
authors = ["grid47"]
title = "Leetcode 1790: Check if One String Swap Can Make Strings Equal"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1790: Check if One String Swap Can Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "n4pxnAHTfeU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int chg = 0, cnt = 0;
        vector<int> frq1(26, 0), frq2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
            if(s1[i] != s2[i]) cnt++;
        }

        return frq1 == frq2 && (cnt == 2 || cnt == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1790.md" >}}
---
{{< youtube n4pxnAHTfeU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1791: Find Center of Star Graph](https://grid47.xyz/leetcode/solution-1791-find-center-of-star-graph/) |
| --- |
