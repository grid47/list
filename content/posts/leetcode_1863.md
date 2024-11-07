
+++
authors = ["Crafted by Me"]
title = "Leetcode 1863: Sum of All Subset XOR Totals"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1863: Sum of All Subset XOR Totals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Backtracking","Bit Manipulation","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0;
            for (auto j = 0; j < nums.size(); ++j)
                if (i & (1 << j))
                    total ^= nums[j];
            res += total;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1863.md" >}}
---
{{< youtube LI7YR-bwNYY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1865: Finding Pairs With a Certain Sum](https://grid47.xyz/posts/leetcode_1865) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
