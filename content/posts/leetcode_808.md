
+++
authors = ["Crafted by Me"]
title = "Leetcode 808: Soup Servings"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 808: Soup Servings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Dynamic Programming","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/soup-servings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
        vector<vector<double>> mem;
public:
    double soupServings(int n) {
        mem.resize(200, vector<double>(200, 0));
        return n > 4800? 1:f((n +24)/25, (n+24)/25);
    }

    double f(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;
        if(mem[a][b] > 0) return mem[a][b];
 mem[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a - 2, b -2) + f(a-1, b-3));
        return mem[a][b];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/808.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #809: Expressive Words](https://grid47.xyz/posts/leetcode_809) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

