
+++
authors = ["grid47"]
title = "Leetcode 1262: Greatest Sum Divisible by Three"
date = "2024-07-03"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1266: Minimum Time Visiting All Points](https://grid47.xyz/posts/leetcode-1266-minimum-time-visiting-all-points-solution/) |
| --- |
