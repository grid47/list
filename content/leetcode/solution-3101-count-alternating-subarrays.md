
+++
authors = ["grid47"]
title = "Leetcode 3101: Count Alternating Subarrays"
date = "2024-01-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3101: Count Alternating Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-alternating-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3101.md" >}}
---
{{< youtube EZSNwFnWaV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3110: Score of a String](https://grid47.xyz/leetcode/solution-3110-score-of-a-string/) |
| --- |
