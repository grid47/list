
+++
authors = ["grid47"]
title = "Leetcode 896: Monotonic Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 896: Monotonic Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/monotonic-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/896.md" >}}
---
{{< youtube stkYclqstaA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #898: Bitwise ORs of Subarrays](https://grid47.xyz/posts/leetcode-898-bitwise-ors-of-subarrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}