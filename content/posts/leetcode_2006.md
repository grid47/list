
+++
authors = ["Crafted by Me"]
title = "Leetcode 2006: Count Number of Pairs With Absolute Difference K"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2006: Count Number of Pairs With Absolute Difference K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {}, res = 0;
        for (auto n : nums)
            ++cnt[n];
        for (int i = k + 1; i < 101; ++i)
            res += cnt[i] * cnt[i - k];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2006.md" >}}
---
{{< youtube noP_AsQlgQc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2007: Find Original Array From Doubled Array](https://grid47.xyz/posts/leetcode_2007) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
