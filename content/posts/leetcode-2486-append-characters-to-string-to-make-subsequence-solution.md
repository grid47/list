
+++
authors = ["grid47"]
title = "Leetcode 2486: Append Characters to String to Make Subsequence"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2486: Append Characters to String to Make Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for(int i = 0; i < s.size() && j < t.size(); i++) {
            j += s[i] == t[j];
        }
        return t.size()-j;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2486.md" >}}
---
{{< youtube gKDmO8ZLRD8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2487: Remove Nodes From Linked List](https://grid47.xyz/posts/leetcode-2487-remove-nodes-from-linked-list-solution/) |
| --- |
