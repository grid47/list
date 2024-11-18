
+++
authors = ["grid47"]
title = "Leetcode 848: Shifting Letters"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 848: Shifting Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = shifts.size();
        for(int i = n - 2; i >= 0; i--)
        shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;

        for(int i = 0; i < s.size(); i++)
        s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);

        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/848.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #851: Loud and Rich](https://grid47.xyz/leetcode/solution-851-loud-and-rich/) |
| --- |
