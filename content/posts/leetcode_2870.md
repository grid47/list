
+++
authors = ["grid47"]
title = "Leetcode 2870: Minimum Number of Operations to Make Array Empty"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2870: Minimum Number of Operations to Make Array Empty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0;
        for (auto [_, cnt] : m) {
            if (cnt == 1)
                return -1;
            res += cnt / 3 + (cnt % 3 > 0);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2870.md" >}}
---
{{< youtube _AcO35R0fss >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2871: Split Array Into Maximum Number of Subarrays](https://grid47.xyz/posts/leetcode_2871) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
