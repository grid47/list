
+++
authors = ["grid47"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2475: Number of Unequal Triplets in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2475.md" >}}
---
{{< youtube AbSMJxiiJpk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2476: Closest Nodes Queries in a Binary Search Tree](https://grid47.xyz/posts/leetcode-2476-closest-nodes-queries-in-a-binary-search-tree-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}