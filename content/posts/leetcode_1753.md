
+++
authors = ["Crafted by Me"]
title = "Leetcode 1753: Maximum Score From Removing Stones"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1753: Maximum Score From Removing Stones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // a > b > c
        if(a < b)
        return maximumScore(b, a, c);
        if(b < c)
        return maximumScore(a, c, b);

        return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1753.md" >}}
---
{{< youtube PfcEkLJ725o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1754: Largest Merge Of Two Strings](https://grid47.xyz/posts/leetcode_1754) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
