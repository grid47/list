
+++
authors = ["Crafted by Me"]
title = "Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s;
    int res = INT_MAX;
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it));
        if (it != end(s))
            res = min(res, *it - nums[i]);
    }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2817.md" >}}
---
{{< youtube iZkBnYIJ9Qc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2824: Count Pairs Whose Sum is Less than Target](https://grid47.xyz/posts/leetcode_2824) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
