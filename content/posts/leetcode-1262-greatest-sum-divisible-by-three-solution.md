
+++
authors = ["grid47"]
title = "Leetcode 1262: Greatest Sum Divisible by Three"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1262: Greatest Sum Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/greatest-sum-divisible-by-three/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(3, 0);

        for(int a : nums)
        for(int i : vector<int>(dp))
        dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);

        return dp[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1262.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1266: Minimum Time Visiting All Points](https://grid47.xyz/posts/leetcode-1266-minimum-time-visiting-all-points-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}