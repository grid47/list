
+++
authors = ["grid47"]
title = "Leetcode 844: Backspace String Compare"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 844: Backspace String Compare in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "TOwf2xKKfJ8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/backspace-string-compare/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/844.md" >}}
---
{{< youtube TOwf2xKKfJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #845: Longest Mountain in Array](https://grid47.xyz/leetcode/solution-845-longest-mountain-in-array/) |
| --- |
