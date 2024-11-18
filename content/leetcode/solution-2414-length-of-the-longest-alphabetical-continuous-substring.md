
+++
authors = ["grid47"]
title = "Leetcode 2414: Length of the Longest Alphabetical Continuous Substring"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2414: Length of the Longest Alphabetical Continuous Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int x = 1, ans = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i -1] +1) {
                x++;
            } else x = 1;
            ans = max(x, ans);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2414.md" >}}
---
{{< youtube TBVr58ynqsI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2415: Reverse Odd Levels of Binary Tree](https://grid47.xyz/leetcode/solution-2415-reverse-odd-levels-of-binary-tree/) |
| --- |
