
+++
authors = ["grid47"]
title = "Leetcode 3138: Minimum Length of Anagram Concatenation"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3146: Permutation Difference between Two Strings](https://grid47.xyz/posts/leetcode-3146-permutation-difference-between-two-strings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}