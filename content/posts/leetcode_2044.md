
+++
authors = ["Yasir"]
title = "Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets"
date = "2019-03-25"
description = "Solution to Leetcode 2044"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        int dp[1 << 17] = {1};
        dp[0] = 1;
        for(int a : nums) {
            for(int i = mx; i >= 0; i--) {
                dp[i | a] += dp[i];
            }
            mx |= a;
        }
        return dp[mx];
    }
};
{{< /highlight >}}

