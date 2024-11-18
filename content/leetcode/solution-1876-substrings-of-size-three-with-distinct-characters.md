
+++
authors = ["grid47"]
title = "Leetcode 1876: Substrings of Size Three with Distinct Characters"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1876: Substrings of Size Three with Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int cnt = 0;
        for(int i = 2; i < s.size(); i++)
            if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;

            return cnt;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1876.md" >}}
---
{{< youtube QIyWjKNstAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1877: Minimize Maximum Pair Sum in Array](https://grid47.xyz/leetcode/solution-1877-minimize-maximum-pair-sum-in-array/) |
| --- |
