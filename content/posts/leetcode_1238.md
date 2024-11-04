
+++
authors = ["Crafted by Me"]
title = "Leetcode 1238: Circular Permutation in Binary Representation"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1238: Circular Permutation in Binary Representation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-permutation-in-binary-representation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for(int i = 0; i < 1 << n; i++)
            res.push_back(start ^ i ^ i >> 1);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1238.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1239: Maximum Length of a Concatenated String with Unique Characters](https://grid47.xyz/posts/leetcode_1239) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

