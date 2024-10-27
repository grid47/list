
+++
authors = ["Yasir"]
title = "Leetcode 300: Longest Increasing Subsequence"
date = "2024-01-02"
description = "Solution to Leetcode 300"
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

{{< highlight html >}}
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

