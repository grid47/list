
+++
authors = ["grid47"]
title = "Leetcode 1209: Remove All Adjacent Duplicates in String II"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1209: Remove All Adjacent Duplicates in String II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk = {{0, '#'}};
        
        for(char c : s) {
            if(stk.back().second != c)
                stk.push_back({1, c});
            else if(++stk.back().first == k)
                stk.pop_back();
        }
        
        string res;
        for(auto x: stk)
            res.append(x.first, x.second);
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1209.md" >}}
---
{{< youtube w6LcypDgC4w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1218: Longest Arithmetic Subsequence of Given Difference](https://grid47.xyz/leetcode/solution-1218-longest-arithmetic-subsequence-of-given-difference/) |
| --- |
