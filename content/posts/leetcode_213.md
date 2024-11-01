
+++
authors = ["Crafted by Me"]
title = "Leetcode 213: House Robber II"
date = "2024-04-03"
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
- by gpt
        
---
{{< youtube rWAJCfYYOvM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

