
+++
authors = ["Crafted by Me"]
title = "Leetcode 338: Counting Bits"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 338: Counting Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/counting-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/338.md" >}}
---
{{< youtube RyBM56RIWrM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #341: Flatten Nested List Iterator](https://grid47.xyz/posts/leetcode_341) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
