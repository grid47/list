
+++
authors = ["grid47"]
title = "Leetcode 2108: Find First Palindromic String in the Array"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2108: Find First Palindromic String in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &w : words)
            if (w == string(rbegin(w), rend(w)))
                return w;
        return "";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2108.md" >}}
---
{{< youtube 4JA5MW772N0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2109: Adding Spaces to a String](https://grid47.xyz/leetcode/solution-2109-adding-spaces-to-a-string/) |
| --- |
