
+++
authors = ["Crafted by Me"]
title = "Leetcode 790: Domino and Tromino Tiling"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 790: Domino and Tromino Tiling in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/domino-and-tromino-tiling/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<long long> v(10001, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        if(n <= 3) return v[n];
        for(int i = 4; i <= n; i++) {
            v[i]  = (2 * v[i-1] + v[i-3]);
            v[i] %= mod;
        }
        return v[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/790.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #791: Custom Sort String](https://grid47.xyz/posts/leetcode_791) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
