
+++
authors = ["grid47"]
title = "Leetcode 365: Water and Jug Problem"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 365: Water and Jug Problem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/water-and-jug-problem/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z || x + y == z) return true;
        return z % gcd(x, y) == 0;
    }

    int gcd(int a, int b) {
        return b == 0? a: gcd(b, a%b);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/365.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #368: Largest Divisible Subset](https://grid47.xyz/posts/leetcode-368-largest-divisible-subset-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}