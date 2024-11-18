
+++
authors = ["grid47"]
title = "Leetcode 2825: Make String a Subsequence Using Cyclic Increments"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2825: Make String a Subsequence Using Cyclic Increments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SfXj_8QoeL8"
youtube_upload_date="2023-08-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SfXj_8QoeL8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0, n = s1.size(), m = s2.size();
        for (int i = 0; i < n && j < m; ++i)
            if (s1[i] == s2[j] || s1[i] + 1 == s2[j] || s1[i] - 25 == s2[j])
                ++j;
        return j == m;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2825.md" >}}
---
{{< youtube SfXj_8QoeL8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2826: Sorting Three Groups](https://grid47.xyz/leetcode/solution-2826-sorting-three-groups/) |
| --- |
