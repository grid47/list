
+++
authors = ["grid47"]
title = "Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> groups;
        int d = 0;
        for(char c: seq) {
            bool open = c == '(';
            if(open) d++;
            groups.push_back(d%2);
            if(!open) d--;
        }
        return groups;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1111.md" >}}
---
{{< youtube lHzdbjyqBG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1114: Print in Order](https://grid47.xyz/leetcode/solution-1114-print-in-order/) |
| --- |
