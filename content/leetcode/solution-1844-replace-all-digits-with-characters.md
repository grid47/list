
+++
authors = ["grid47"]
title = "Leetcode 1844: Replace All Digits with Characters"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1844: Replace All Digits with Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "L5P6zYBLP3s"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/replace-all-digits-with-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string replaceDigits(string s) {
    for (auto i = 1; i < s.size(); i += 2)
        s[i] += s[i - 1] - '0';
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1844.md" >}}
---
{{< youtube L5P6zYBLP3s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1845: Seat Reservation Manager](https://grid47.xyz/leetcode/solution-1845-seat-reservation-manager/) |
| --- |
