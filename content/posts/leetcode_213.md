
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 213: House Robber II"
date = "2024-04-01"
description = "Solution to Leetcode 213"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/house-robber-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            
        int r1 = dp[n - 1];
        
        dp.resize(n + 1, 0);
        dp[1] = 0;
        dp[2] = nums[1];        
        for(int i = 3; i < n + 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);        
        
        return max(dp[n], r1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/213.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

