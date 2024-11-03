
+++
authors = ["Crafted by Me"]
title = "Leetcode 300: Longest Increasing Subsequence"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 300: Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-increasing-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/300.md" >}}
---
{{< youtube VZc93A5v1JI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #301: Remove Invalid Parentheses](https://grid47.xyz/posts/leetcode_301) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

