
+++
authors = ["grid47"]
title = "Leetcode 1638: Count Substrings That Differ by One Character"
date = "2024-05-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1638: Count Substrings That Differ by One Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
            res += helper(s, t, i, 0);
        for(int j = 1; j < t.size(); j++)
            res += helper(s, t, 0, j);
        return res;
    }

    int helper(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        for(int n = s.size(), m = t.size(); i < n && j < m; i++, j++) {
            cur++;
            if(s[i] != t[j]) {
                pre = cur;
                cur = 0;
            }
            res += pre;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1638.md" >}}
---
{{< youtube QOmHQiUMBuI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1642: Furthest Building You Can Reach](https://grid47.xyz/posts/leetcode-1642-furthest-building-you-can-reach-solution/) |
| --- |
