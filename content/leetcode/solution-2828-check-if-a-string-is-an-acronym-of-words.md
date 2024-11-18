
+++
authors = ["grid47"]
title = "Leetcode 2828: Check if a String Is an Acronym of Words"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2828: Check if a String Is an Acronym of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "GcgV-AtAmkg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        for(string w: words)
            res += w[0];
        return s == res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2828.md" >}}
---
{{< youtube GcgV-AtAmkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2829: Determine the Minimum Sum of a k-avoiding Array](https://grid47.xyz/leetcode/solution-2829-determine-the-minimum-sum-of-a-k-avoiding-array/) |
| --- |
