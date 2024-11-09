
+++
authors = ["grid47"]
title = "Leetcode 2274: Maximum Consecutive Floors Without Special Floors"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2274: Maximum Consecutive Floors Without Special Floors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spec) {

        sort(spec.begin(), spec.end());
        int prv = bottom - 1, n = spec.size();

        int res = 0;
        for(int cur : spec) {
            res = max(res, cur - prv - 1);
            prv = cur > prv ? cur : prv;
        }
        res = max(res, top - prv);

        return res;
    }
};

// bottom - top
// spec
// 
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2274.md" >}}
---
{{< youtube ZQ6iiXxEhRY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2275: Largest Combination With Bitwise AND Greater Than Zero](https://grid47.xyz/posts/leetcode-2274-maximum-consecutive-floors-without-special-floors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
