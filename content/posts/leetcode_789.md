
+++
authors = ["Crafted by Me"]
title = "Leetcode 789: Escape The Ghosts"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 789: Escape The Ghosts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/escape-the-ghosts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        for(auto it: gs)
        if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
        return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/789.md" >}}
---
{{< youtube fCx9Fb_ghaA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #790: Domino and Tromino Tiling](https://grid47.xyz/posts/leetcode_790) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
