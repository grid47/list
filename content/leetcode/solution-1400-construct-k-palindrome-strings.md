
+++
authors = ["grid47"]
title = "Leetcode 1400: Construct K Palindrome Strings"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1400: Construct K Palindrome Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for(char c: s)
        odd.flip(c - 'a');
        return odd.count() <= k && k <= s.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1400.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1401: Circle and Rectangle Overlapping](https://grid47.xyz/leetcode/solution-1401-circle-and-rectangle-overlapping/) |
| --- |
