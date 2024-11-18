
+++
authors = ["grid47"]
title = "Leetcode 925: Long Pressed Name"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 925: Long Pressed Name in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/long-pressed-name/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
        bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        return i == m;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/925.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #926: Flip String to Monotone Increasing](https://grid47.xyz/leetcode/solution-926-flip-string-to-monotone-increasing/) |
| --- |
