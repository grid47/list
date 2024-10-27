
+++
authors = ["Yasir"]
title = "Leetcode 3101: Count Alternating Subarrays"
date = "2016-05-02"
description = "Solution to Leetcode 3101"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-alternating-subarrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        dp[0] = 1;
        long long res = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = nums[i] == nums[i - 1]? 1: dp[i - 1] + 1;
            // cout << dp[i];
            res += dp[i];
        }
        return res;
    }
};
{{< /highlight >}}

