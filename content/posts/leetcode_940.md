
+++
authors = ["Crafted by Me"]
title = "Leetcode 940: Distinct Subsequences II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 940: Distinct Subsequences II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-subsequences-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctSubseqII(string S) {
        int endsWith[26] = {}, mod = 1e9 + 7;
        auto lambda = [&](int s, int i) {return (s + i) % mod; };
        for (char c : S)
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1, lambda);
        return accumulate(begin(endsWith), end(endsWith), 0, lambda);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/940.md" >}}
---
{{< youtube BSOCMf696Ao >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #941: Valid Mountain Array](https://grid47.xyz/posts/leetcode_941) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

