
+++
authors = ["grid47"]
title = "Leetcode 2873: Maximum Value of an Ordered Triplet I"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2873: Maximum Value of an Ordered Triplet I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, mxa = 0, mxab = 0;
        for(long a: nums) {
            res = max(res, mxab * a);
            mxab = max(mxab, mxa - a);
            mxa = max(mxa, a);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2873.md" >}}
---
{{< youtube U0abRgobTKg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2874: Maximum Value of an Ordered Triplet II](https://grid47.xyz/posts/leetcode-2874-maximum-value-of-an-ordered-triplet-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}