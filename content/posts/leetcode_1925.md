
+++
authors = ["grid47"]
title = "Leetcode 1925: Count Square Sum Triples"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1925: Count Square Sum Triples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-square-sum-triples/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriples(int n) {
    vector<bool> squares(n * n + 1);
    for (int i = 1; i <= n; ++i)
        squares[i * i] = true;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; i * i + j * j <= n * n; ++j)
            res += squares[i * i + j * j] * 2;
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1925.md" >}}
---
{{< youtube rWLEDxwWwiU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1926: Nearest Exit from Entrance in Maze](https://grid47.xyz/posts/leetcode_1926) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
