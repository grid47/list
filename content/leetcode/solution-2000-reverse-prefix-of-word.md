
+++
authors = ["grid47"]
title = "Leetcode 2000: Reverse Prefix of Word"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2000: Reverse Prefix of Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-prefix-of-word/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(begin(word), begin(word) + p + 1);
        return word;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2000.md" >}}
---
{{< youtube jVRdLKA6t4k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2001: Number of Pairs of Interchangeable Rectangles](https://grid47.xyz/leetcode/solution-2001-number-of-pairs-of-interchangeable-rectangles/) |
| --- |
