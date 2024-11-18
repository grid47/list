
+++
authors = ["grid47"]
title = "Leetcode 1754: Largest Merge Of Two Strings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1754: Largest Merge Of Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "YB-A6OUj98o"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/largest-merge-of-two-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestMerge(string w1, string w2) {
        if (w1 == "" || w2 == "")
            return w1 + w2;
        else if (w1 < w2)
            return w2[0] + largestMerge(w1, w2.substr(1));
        else return w1[0] + largestMerge(w1.substr(1), w2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1754.md" >}}
---
{{< youtube YB-A6OUj98o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1758: Minimum Changes To Make Alternating Binary String](https://grid47.xyz/leetcode/solution-1758-minimum-changes-to-make-alternating-binary-string/) |
| --- |
