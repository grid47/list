
+++
authors = ["grid47"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 168: Excel Sheet Column Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/excel-sheet-column-title/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/168.webp" 
    alt="A radiant column title unfolding slowly, forming the Excel-style alphanumeric title."
    caption="Solution to LeetCode 168: Excel Sheet Column Title Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int mod;
        while(columnNumber > 0) {
            mod = --columnNumber % 26;
            char x = ('A' + mod);
            res = x + res;
            columnNumber /= 26;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/168.md" >}}
---
{{< youtube X_vJDpCCuoA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #169: Majority Element](https://grid47.xyz/posts/leetcode-169-majority-element-solution/) |
| --- |
