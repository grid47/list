
+++
authors = ["grid47"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2016: Maximum Difference Between Increasing Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2016.md" >}}
---
{{< youtube OmNZRgKr7GQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2017: Grid Game](https://grid47.xyz/posts/leetcode-2017-grid-game-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}