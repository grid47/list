
+++
authors = ["grid47"]
title = "Leetcode 1961: Check If String Is a Prefix of Array"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1961: Check If String Is a Prefix of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int k = 0, l = 0, i = 0;
        for(i = 0; i < s.size() && k < w.size(); i++) {
            
            if(s[i] != w[k][l]) return false;
            
            l++;
            
            if(l == w[k].size()) {
                k++;
                l = 0;
            }
        }
        if(i != s.size()) return false;
        return (l == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1961.md" >}}
---
{{< youtube msS6F5DL8gQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1962: Remove Stones to Minimize the Total](https://grid47.xyz/leetcode/solution-1962-remove-stones-to-minimize-the-total/) |
| --- |
