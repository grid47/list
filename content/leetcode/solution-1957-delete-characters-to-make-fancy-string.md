
+++
authors = ["grid47"]
title = "Leetcode 1957: Delete Characters to Make Fancy String"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1957: Delete Characters to Make Fancy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeFancyString(string s) {
        int j = 2;
        for (int i = 2; i < s.size(); ++i)
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        s.resize(min(j, (int)s.size()));
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1957.md" >}}
---
{{< youtube wdve85GSjO8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1958: Check if Move is Legal](https://grid47.xyz/leetcode/solution-1958-check-if-move-is-legal/) |
| --- |
