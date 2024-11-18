
+++
authors = ["grid47"]
title = "Leetcode 3138: Minimum Length of Anagram Concatenation"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3138: Minimum Length of Anagram Concatenation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAnagramLength(string s) {
        // 12,  4
        // aaxxbb
        // bbxxaa

        int n = s.size();
        map<char, int> mp;        
        for(char x: s)
            mp[x]++;

        int mn = mp[s[0]];
        for(auto it: mp)
        mn = __gcd(mn, it.second);

        return n / mn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3138.md" >}}
---
{{< youtube T64iR68Fxng >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3146: Permutation Difference between Two Strings](https://grid47.xyz/leetcode/solution-3146-permutation-difference-between-two-strings/) |
| --- |
