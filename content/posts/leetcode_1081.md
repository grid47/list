
+++
authors = ["Crafted by Me"]
title = "Leetcode 1081: Smallest Subsequence of Distinct Characters"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1081: Smallest Subsequence of Distinct Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string res = "";

        vector<int> in(26, 0), seen(26, 0);
        for (int i = 0; i < n; i++)
            in[s[i] - 'a'] = i;

        vector<int> stk;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (seen[c]++ > 0) continue;
            while (!stk.empty() && stk.back() > c && i < in[stk.back()]) {
                seen[stk.back()] = 0;
                stk.pop_back();
            }
            stk.push_back(c);
        }

        for (int i = 0; i < stk.size(); i++)
            res += ('a' + stk[i]);

        return res;
    }
};

// that problem was there were
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1081.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1084: Sales Analysis III](https://grid47.xyz/posts/leetcode_1084) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
