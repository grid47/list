
+++
authors = ["grid47"]
title = "Leetcode 2839: Check if Strings Can be Made Equal With Operations I"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2839: Check if Strings Can be Made Equal With Operations I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        if(s1[0] != s2[0]) swap(s1[0],s1[2]);
        if(s1 == s2) return true;
        
        if(s1[1] != s2[1]) swap(s1[1],s1[3]);
        if(s1 == s2) return true;
        
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2839.md" >}}
---
{{< youtube b46PWRWHFp4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2840: Check if Strings Can be Made Equal With Operations II](https://grid47.xyz/leetcode/solution-2840-check-if-strings-can-be-made-equal-with-operations-ii/) |
| --- |
