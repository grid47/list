
+++
authors = ["Crafted by Me"]
title = "Leetcode 2029: Stone Game IX"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2029: Stone Game IX in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Counting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-ix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> m(3, 0);
        for(int a: stones)
        m[a % 3]++;
        if(min(m[2], m[1]) == 0)
        return max(m[1], m[2]) > 2 && m[0] % 2 >0;
        return abs(m[1] - m[2]) > 2 || m[0] % 2 == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2029.md" >}}
---
{{< youtube 7r34JD5ud-c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2033: Minimum Operations to Make a Uni-Value Grid](https://grid47.xyz/posts/leetcode_2033) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
